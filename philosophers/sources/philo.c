/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:58:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/22 18:55:13 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


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
// die eat sleep


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
	dinner.list_t_philos = philosophers; //UGLY BUT IT IS LIFE
	for (int i = 0; i < dinner.philos; i++)
	{
		printf("philo %i has left fork %p and right fork %p\n", i, philosophers[i].left_fork, philosophers[i].right_fork);
	}
	
	if (!philosophers)
	{	
		printf("hi in fail malloc");
		return(1); //free forks and update err
	}	
	if (dinner.philos == 1)
		lonely_philosopher(&dinner);
	else
		create_threads(&dinner, philosophers);
	
	pthread_mutex_destroy(&dinner.write);
	pthread_mutex_destroy(&dinner.mutex);
	pthread_mutex_destroy(&dinner.death);
	
	for (int i = 0; i < dinner.philos; i++)
	{
		pthread_mutex_destroy(&philosophers[i].last_meal); //mutex of each last meal time
		pthread_mutex_destroy(&philosophers[i].mutex_meals_eaten_mutex); // how many meals
		pthread_mutex_destroy(&philosophers[i].mutex_is_eating);
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
		//I will most likely come back here to add stuff // this is kinda experimental
		pthread_mutex_init(&(philosophers[i].last_meal), NULL);
		pthread_mutex_init(&(philosophers[i].mutex_meals_eaten_mutex), NULL);
		pthread_mutex_init(&philosophers[i].mutex_is_eating, NULL);
		philosophers[i].is_eating = false;
		philosophers[i].alive = true;
		philosophers[i].dinner = dinner;
		philosophers[i].id = i + 1;
		philosophers[i].write = &dinner->write;
		philosophers[i].left_fork = &forks[i];
		// philosophers[i].last_meal_time = 0;
		if (i + 1 == dinner->philos)
			philosophers[i].right_fork = &forks[0];
		else
			philosophers[i].right_fork = &forks[i + 1];
		philosophers[i].start_time = get_current_time(); // in theory this is dumb and wrong
		i++;
	}
	return (philosophers);
}

int create_threads(t_dinner *dinner, t_philo *philosophers)
{
	int i;
	
	i = 0;
	printf("hi guys numer of philos = %li\n", dinner->philos);
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
	if (pthread_create(&dinner->death_checker, NULL, death_check, dinner) != 0) //idk if this should be before or after
			printf("failed to create thread"); // cant just perror
	i = 0;
	if (pthread_join(dinner->death_checker, NULL) != 0)
			perror("failed to join thread");
	while (i < dinner->philos)
	{
		if (pthread_join(dinner->philos_list_thread[i], NULL) != 0)
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
	long time;
	
	philo = (t_philo *)arg;
	// philo->start_time = get_current_time(); //trying to set it outside of a thread but maybe its a bad idea
	setter(&philo->last_meal_time, philo->start_time, &philo->last_meal);
	// philo->last_meal_time = philo->start_time;
	// if (philo->id % 2 == 0)
	// 	usleep(500);
	philo_grindset(philo);
	// mutex_write(philo, "philo is chilling\n", philo->id);
	return (NULL);
}

void    init_dinner_variables(t_dinner *dinner, const char **argv, int argc)
{
	pthread_mutex_init(&dinner->mutex, NULL);
	pthread_mutex_init(&dinner->write, NULL);
	pthread_mutex_init(&dinner->death, NULL);
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
