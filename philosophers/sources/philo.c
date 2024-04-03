/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:58:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/03 15:25:22 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int    	init_dinner_variables(t_dinner *dinner, const char **argv, int argc);
void    	lonely_philosopher(t_dinner *dinner);
void		*routine(void *arg);
int     	create_threads(t_dinner *dinner, t_philo *philosophers);
void    	*lonely_routine(void *arg);
pthread_mutex_t *init_forks(long philos);
t_philo			*init_philosophers(t_philo	*philosophers, t_dinner *dinner);
int	init_dinner_mutexes(t_dinner *dinner);

int main(int argc, char const *argv[])
{
	t_dinner 		dinner;
	

	memset(&dinner, 0, sizeof(t_dinner));
	if (init_dinner_variables(&dinner, argv, argc) == 0)
		return (1);
	dinner.forks = init_forks(dinner.philos);
	if (!dinner.forks)
	{
		pthread_mutex_destroy(&dinner.write);
		pthread_mutex_destroy(&dinner.death);
		pthread_mutex_destroy(&dinner.dinner_start);
		return (1);
	}

	dinner.list_t_philos = init_philosophers(dinner.list_t_philos, &dinner);
	if (!dinner.list_t_philos)
		return (1); //free forks and update err
	if (dinner.philos == 1)
		lonely_philosopher(&dinner);
	else
		create_threads(&dinner, dinner.list_t_philos);
	
	pthread_mutex_destroy(&dinner.write);
	pthread_mutex_destroy(&dinner.death);
	pthread_mutex_destroy(&dinner.dinner_start);
	
	for (int i = 0; i < dinner.philos; i++)
	{
		pthread_mutex_destroy(&dinner.list_t_philos[i].last_meal); //mutex of each last meal time
		pthread_mutex_destroy(&dinner.list_t_philos[i].mutex_meals_eaten_mutex); // how many meals
		pthread_mutex_destroy(&dinner.forks[i]); // each fork
	}
	free(dinner.philos_list_thread);
	free(dinner.list_t_philos);
	free(dinner.forks);
	return (0);
}
t_philo			*init_philosophers(t_philo	*philosophers, t_dinner *dinner)
{
	int	i;
	
	philosophers = malloc(sizeof(t_philo) * dinner->philos);
	if (!philosophers)
	{	
		pthread_mutex_destroy(&dinner->write);
		pthread_mutex_destroy(&dinner->death);
		pthread_mutex_destroy(&dinner->dinner_start);
		i = -1;
		while (++i < dinner->philos)
			pthread_mutex_destroy(&dinner->forks[i]);
		free(dinner->forks);
		return (error_and_return_NULL("Philo malloc failed"));
	}
	i = 0;
	while (i < dinner->philos)
	{
		memset(&philosophers[i], 0, sizeof(t_philo));
		pthread_mutex_init(&(philosophers[i].last_meal), NULL);
		pthread_mutex_init(&(philosophers[i].mutex_meals_eaten_mutex), NULL);
		philosophers[i].alive = true;
		philosophers[i].dinner = dinner;
		philosophers[i].id = i + 1;
		philosophers[i].write = &dinner->write;
		if (i == 0)
		{	
			philosophers[i].fork_1 = &dinner->forks[dinner->philos - 1];
			philosophers[i].fork_2 = &dinner->forks[i];
		}
		else if (i % 2 == 0)
		{
			philosophers[i].fork_1 = &dinner->forks[i - 1];
			philosophers[i].fork_2 = &dinner->forks[i];
		}
		else
		{
			philosophers[i].fork_2 = &dinner->forks[i - 1];
			philosophers[i].fork_1 = &dinner->forks[i];	
		}
		i++;
	}
	return (philosophers);
}

int create_threads(t_dinner *dinner, t_philo *philosophers)
{
	int i;
	
	i = 0;
	dinner->philos_list_thread = malloc(sizeof(pthread_t) * dinner->philos);
	if (!dinner->philos_list_thread)
		return (0); // error checking later;
	while (i < dinner->philos)
	{
		// ft_printf("hi in create loop\n");
		if (pthread_create(&dinner->philos_list_thread[i], NULL, routine, &philosophers[i]) != 0)
			printf("failed to create thread"); // cant just perror
		i++;
	}
	if (pthread_create(&dinner->death_checker, NULL, the_watcher, dinner) != 0) //idk if this should be before or after
			printf("failed to create thread"); // cant just perror
	dinner->start_time = get_time();
	setter_bool(&dinner->is_dinner_started, true, &dinner->dinner_start); // maybe this need mutex who knows
	i = 0;
	while (i < dinner->philos)
	{
		if (pthread_join(dinner->philos_list_thread[i], NULL) != 0)
			perror("failed to join thread");
		i++;
	}
	if (pthread_join(dinner->death_checker, NULL) != 0)
			perror("failed to join thread");
	return (1);
}


void    *lonely_routine(void *arg)
{
	t_dinner *dinner;
	struct timeval start;
	struct timeval end;
	long long   time; // maybe change this later;

	dinner = (t_dinner *)arg;
	time = 0;
	gettimeofday(&start, NULL);
	printf("%lld philosopher has taken a fork\n", time);
	gettimeofday(&end, NULL);
	gettimeofday(&start, NULL);
	ft_usleep(dinner->time_to_die * 1000); //this is wrong i think
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
	// for (int i = 0; i < dinner.philos; i++)
	// {
	// 	printf("philo %i has left fork %p and right fork %p\n", i, philosophers[i].fork_1, philosophers[i].fork_2);
	// }
