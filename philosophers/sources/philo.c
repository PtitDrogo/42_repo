/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:58:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/18 18:03:41 by tfreydie         ###   ########.fr       */
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
void	*routine(void *arg);
int     create_philos(t_dinner *dinner);
void    *lonely_routine(void *arg);

void	ft_free_array(void **array)
{
	int	j;

	j = 0;
	if (!array)
		return ;
	while (array[j])
	{
		if (array[j])
			free(array[j]);
		j++;
	}
	free(array);
	return ;
}

int main(int argc, char const *argv[])
{
	t_dinner dinner;
	memset(&dinner, 0, sizeof(dinner));
	if (argc < 5)
		return (perror("invalid number of arguments"), 1); //edit errno
	init_dinner_variables(&dinner, argv, argc);
	if (dinner.philos == 1)
		lonely_philosopher(&dinner);
	else
	{
		create_philos(&dinner);
	}
	free(dinner.philos_list);
	pthread_mutex_destroy(&dinner.mutex);
	return (0);
}

int create_philos(t_dinner *dinner)
{
	int i;
	
	i = 0;
	printf("hi guys philos = %li\n", dinner->philos);
	dinner->philos_list = malloc(sizeof(pthread_t) * dinner->philos);
	if (!dinner->philos_list)
		return (0); // error checking later;
	while (i < dinner->philos)
	{
		// ft_printf("hi in create loop\n");
		if (pthread_create(&dinner->philos_list[i], NULL, routine, dinner) != 0)
			printf("failed to create thread"); // cant just perror
		i++;
	}
	i = 0;
	while (i < dinner->philos)
	{
		if (pthread_join(dinner->philos_list[i], NULL) != 0)
			perror("failed to join thread");
		i++;
	}
	return (1);
	
}

void *routine(void *arg)
{
	t_dinner *dinner;
	
	dinner = (t_dinner *)arg;
	increment(&(dinner->synchronise), &(dinner->mutex));
	while (getter(&(dinner->synchronise), &(dinner->mutex)) < dinner->philos)
		usleep(10);
	return (NULL);
}

void    init_dinner_variables(t_dinner *dinner, const char **argv, int argc)
{
	pthread_mutex_init(&dinner->mutex, NULL);
	dinner->philos = atol(argv[1]);
	dinner->fork = dinner->philos;
	dinner->time_to_die = atol(argv[2]); //safeguard this && no atol
	dinner->time_to_eat = atol(argv[3]);
	dinner->time_to_sleep = atol(argv[4]);
	if (argc == 6)
		dinner->min_meals = atol(argv[5]);
}

void    *lonely_routine(void *arg)
{
	t_dinner *dinner;
	struct timeval start;
	struct timeval end;
	long long   time; // maybe change this later;

	dinner = (t_dinner *)arg;
	gettimeofday(&start, NULL);
	printf("%lld philosopher has taken a fork\n", time);
	gettimeofday(&end, NULL);
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
	
	if (pthread_create(&philo, NULL, lonely_routine, (void *)dinner) != 0) 
		return ; // update
	if (pthread_join(philo, NULL) != 0) 
		return ;
}
