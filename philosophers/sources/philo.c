/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:58:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/19 15:50:58 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>

void    	init_dinner_variables(t_dinner *dinner, const char **argv, int argc);
void    	lonely_philosopher(t_dinner *dinner);
void		*routine(void *arg);
int     	create_threads(t_dinner *dinner, t_philo *philosophers);
void    	*lonely_routine(void *arg);
pthread_mutex_t *init_forks(long philos);
t_philo			*init_philosophers(t_philo	*philosophers, t_dinner *dinner, pthread_mutex_t *forks);

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
	t_dinner 		dinner;
	pthread_mutex_t *forks;
	t_philo			*philosophers;
	
	memset(&dinner, 0, sizeof(dinner));
	if (argc < 5)
		return (perror("invalid number of arguments"), 1); //edit errno
	init_dinner_variables(&dinner, argv, argc);
	forks = init_forks(dinner.philos);
	if (!forks)
		return (1); //UPDATE WITH ERROR MESSAGE
	philosophers = init_philosophers(philosophers, &dinner, forks);
	if (!philosophers)
	{	
		printf("hi in fail malloc");
		return(1); //free forks and update err
	}	
	if (dinner.philos == 1)
		lonely_philosopher(&dinner);
	else
	{
		create_threads(&dinner, philosophers);
	}
	free(dinner.philos_list);
	free(forks);
	free(philosophers);
	pthread_mutex_destroy(&dinner.mutex);
	return (0);
}
t_philo			*init_philosophers(t_philo	*philosophers, t_dinner *dinner, pthread_mutex_t *forks)
{
	int	i;
	
	philosophers = malloc(sizeof(t_philo) * dinner->philos);
	if (!philosophers)
		return (NULL); //and free forks;
	i = 0;
	while (i < dinner->philos)
	{
		//I will most likely come back here to add stuff
		philosophers[i].alive = true;
		philosophers[i].dinner = dinner;
		philosophers[i].id = i;
		philosophers[i].write = &dinner->write;
		philosophers[i].left_fork = &forks[i];
		if (i + 1 == dinner->philos)
			philosophers[i].right_fork = &forks[0];
		else
			philosophers[i].right_fork = &forks[i + 1];
		i++;
	}
	return (philosophers);
}

int create_threads(t_dinner *dinner, t_philo *philosophers)
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
		if (pthread_create(&dinner->philos_list[i], NULL, routine, &philosophers[i]) != 0)
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
	t_philo *philo;
	struct timeval start;
	struct timeval end;
	long long   time;
	
	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->write);
	// printf("hi, i am a philosopher and my id is %i\n", philo->id);
	pthread_mutex_unlock(philo->write);
	gettimeofday(&start, NULL);
	usleep(9000);
	gettimeofday(&end, NULL);
	time = (end.tv_sec - start.tv_sec) * 1000LL;
	time += (end.tv_usec - start.tv_usec) / 1000;
	pthread_mutex_lock(philo->write);
	printf("%lli philo %i is chilling\n", time, philo->id);
	pthread_mutex_unlock(philo->write);
	// increment(&(dinner->synchronise), &(dinner->mutex));
	// while (getter(&(dinner->synchronise), &(dinner->mutex)) < dinner->philos)
	// 	usleep(10);
	
	return (NULL);
}

void    init_dinner_variables(t_dinner *dinner, const char **argv, int argc)
{
	pthread_mutex_init(&dinner->mutex, NULL);
	pthread_mutex_init(&dinner->write, NULL);
	dinner->philos = atol(argv[1]);
	dinner->time_to_die = atol(argv[2]);
	dinner->time_to_eat = atol(argv[3]);
	dinner->time_to_sleep = atol(argv[4]);
	if (argc == 6)
		dinner->min_meals = atol(argv[5]);
	
}
pthread_mutex_t *init_forks(long philos)
{
	pthread_mutex_t *forks;
	int	i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * philos);
	if (!forks)
		return (NULL); //TODO update but maybe no
	while (i < philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
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
