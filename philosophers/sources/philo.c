/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:58:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/15 18:55:30 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>

void    init_dinner_variables(t_dinner *dinner, const char **argv, int argc);
void    lonely_philosopher(t_dinner *dinner);

int main(int argc, char const *argv[])
{
    t_dinner dinner;
    memset(&dinner, 0, sizeof(dinner));
    if (argc < 5)
        return (perror("invalid number of arguments"), 1); //edit errno
    init_dinner_variables(&dinner, argv, argc);
    if (dinner.philos == 1)
        lonely_philosopher(&dinner);

    return (0);
}
void    init_dinner_variables(t_dinner *dinner, const char **argv, int argc)
{
    dinner->philos = atoi(argv[1]);
    dinner->fork = dinner->philos;
    dinner->time_to_die = atoi(argv[2]); //safeguard this && no atoi
    dinner->time_to_eat = atoi(argv[3]);
    dinner->time_to_sleep = atoi(argv[4]);
    if (argc == 6)
        dinner->min_meals = atoi(argv[5]);
}

void    *test_routine(void *arg)
{
    t_dinner *dinner;
    struct timeval start;
    struct timeval end;
    long long   time; // maybe change this later;

    dinner = (t_dinner *)arg;
    gettimeofday(&start, NULL);
    usleep(dinner->time_to_die * 1000);
    gettimeofday(&end, NULL);
    time = (end.tv_sec - start.tv_sec) * 1000LL;
    time += (end.tv_usec - start.tv_usec) / 1000;
    printf("%lld philosopher died alone\n", time);
    return (NULL);
    
}


void    lonely_philosopher(t_dinner *dinner)
{
    pthread_t philo;
    
    if (pthread_create(&philo, NULL, (void *)test_routine, (void *)dinner) != 0) 
        return ; // update
    if (pthread_join(philo, NULL) != 0) 
        return ;
}
