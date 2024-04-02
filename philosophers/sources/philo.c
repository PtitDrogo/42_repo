/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptitdrogo <ptitdrogo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:58:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/02 12:59:26 by ptitdrogo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int    	init_dinner_variables(t_dinner *dinner, const char **argv, int argc);
void    	lonely_philosopher(t_dinner *dinner);
void		*routine(void *arg);
int     	create_threads(t_dinner *dinner, t_philo *philosophers);
void    	*lonely_routine(void *arg);
pthread_mutex_t *init_forks(long philos);
t_philo			*init_philosophers(t_philo	*philosophers, t_dinner *dinner, pthread_mutex_t *forks);

int main(int argc, char const *argv[])
{
	t_dinner 		dinner;
	pthread_mutex_t *forks;
	t_philo			*philosophers;
	
	memset(&dinner, 0, sizeof(t_dinner));
	if (argc < 5)
		return (perror("invalid number of arguments"), 1);
	if (init_dinner_variables(&dinner, argv, argc) == 0)
		return (1); //update with error
	forks = init_forks(dinner.philos);
	if (!forks)
		return (1); //UPDATE WITH ERROR MESSAGE
	philosophers = NULL;
	philosophers = init_philosophers(philosophers, &dinner, forks);
	if (!philosophers)
		return (1); //free forks and update err
	dinner.list_t_philos = philosophers; //UGLY BUT IT IS LIFE
	if (dinner.philos == 1)
		lonely_philosopher(&dinner);
	else
		create_threads(&dinner, philosophers);
	
	pthread_mutex_destroy(&dinner.write);
	pthread_mutex_destroy(&dinner.death);
	pthread_mutex_destroy(&dinner.dinner_start);
	
	for (int i = 0; i < dinner.philos; i++)
	{
		pthread_mutex_destroy(&philosophers[i].last_meal); //mutex of each last meal time
		pthread_mutex_destroy(&philosophers[i].mutex_meals_eaten_mutex); // how many meals
		pthread_mutex_destroy(&forks[i]); // each fork
	}
	free(dinner.philos_list_thread);
	free(philosophers);
	free(forks);
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
		memset(&philosophers[i], 0, sizeof(t_philo));
		pthread_mutex_init(&(philosophers[i].last_meal), NULL);
		pthread_mutex_init(&(philosophers[i].mutex_meals_eaten_mutex), NULL);
		philosophers[i].alive = true;
		philosophers[i].dinner = dinner;
		philosophers[i].id = i + 1;
		philosophers[i].write = &dinner->write;
		if (i == 0)
		{	
			philosophers[i].fork_1 = &forks[dinner->philos - 1];
			philosophers[i].fork_2 = &forks[i];
		}
		else if (i % 2 == 0)
		{
			philosophers[i].fork_1 = &forks[i - 1];
			philosophers[i].fork_2 = &forks[i];
		}
		else
		{
			philosophers[i].fork_2 = &forks[i - 1];
			philosophers[i].fork_1 = &forks[i];	
		}
		i++;
	}
	return (philosophers);
}

int create_threads(t_dinner *dinner, t_philo *philosophers)
{
	int i;
	
	i = 0;
	// printf("hi guys numer of philos = %li\n", dinner->philos);
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

void *routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;
	while (getter_bool(&philo->dinner->is_dinner_started, &philo->dinner->dinner_start) == false)
	{
		ft_usleep(500);
	}
	// setter(&philo->last_meal_time, philo->dinner->start_time, &philo->last_meal);
	// setter(&philo->last_meal_time, 0, &philo->last_meal);
	if (philo->id % 2 == 0)
		ft_usleep(5000); // This makes things worse ?????? Sometimes ?? idk ??
	philo_grindset(philo);
	return (NULL);
}

int    init_dinner_variables(t_dinner *dinner, const char **argv, int argc)
{
	if (is_args_valid(argc, (char **)argv) == 0)
	{	
		printf("Invalid arguments\n");
		return (0); //maybe need to free stuff idk
	}
	pthread_mutex_init(&dinner->write, NULL);
	pthread_mutex_init(&dinner->death, NULL);
	pthread_mutex_init(&dinner->dinner_start, NULL);
	dinner->philos = basic_safe_atol(argv[1]);
	dinner->time_to_die = basic_safe_atol(argv[2]);
	dinner->time_to_eat = basic_safe_atol(argv[3]);
	dinner->time_to_sleep = basic_safe_atol(argv[4]);
	if (argc == 6)
		dinner->meals_goal = basic_safe_atol(argv[5]);
	else
		dinner->meals_goal = -1;
	if (dinner->philos == ATOL_ERROR || dinner->time_to_die == ATOL_ERROR || dinner->time_to_eat == ATOL_ERROR || dinner->time_to_sleep == ATOL_ERROR || dinner->meals_goal == ATOL_ERROR)
	{	
		printf("Variable bigger than long int\n");
		return (0); //maybe need to free stuff idk
	}
	dinner->time_to_sleep *= 1000;
	dinner->time_to_eat *= 1000;
	dinner->is_dinner_started = false;
	return (1);
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
