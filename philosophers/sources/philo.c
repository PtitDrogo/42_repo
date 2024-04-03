/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:58:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/03 17:07:50 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int    		init_dinner_variables(t_dinner *dinner, const char **argv, int argc);
void    	lonely_philosopher(t_dinner *dinner);
void		*routine(void *arg);
int     	create_threads(t_dinner *dinner, t_philo *philosophers);
void    	*lonely_routine(void *arg);

int		init_philosophers(t_philo	*philosophers, t_dinner *dinner);
int		init_dinner_mutexes(t_dinner *dinner);
void	philosopher_fork_behavior(int i, t_philo	*philosophers, t_dinner *dinner);
int		init_all(t_dinner *dinner, int argc, char const **argv);

int main(int argc, char const *argv[])
{
	t_dinner 		dinner;
	
	memset(&dinner, 0, sizeof(t_dinner));
	if (init_all(&dinner, argc, argv) == 0)
		return (1);
	if (dinner.philos == 1)
		lonely_philosopher(&dinner);
	else
		if (create_threads(&dinner, dinner.list_t_philos) == 0)
			return (1);
	total_cleanup(&dinner);
	return (0);
}
int		init_all(t_dinner *dinner, int argc, char const **argv)
{
	if (init_dinner_variables(dinner, argv, argc) == 0)
		return (0);
	if (init_forks(dinner) == 0)
		return (0);
	if (init_philosophers(dinner->list_t_philos, dinner) == 0)
		return (0);
	return (1);
}

int		init_philosophers(t_philo	*philosophers, t_dinner *dinner)
{
	int	i;
	
	philosophers = malloc(sizeof(t_philo) * dinner->philos);
	if (!philosophers)
	{	
		philo_cleanup(dinner);
		return (error_and_return_0("Philo malloc failed"));
	}
	i = 0;
	while (i < dinner->philos)
	{
		memset(&philosophers[i], 0, sizeof(t_philo));
		if (pthread_mutex_init(&(philosophers[i].last_meal), NULL) != 0)
		{	
			free(philosophers);
			philo_cleanup(dinner);
			return (error_and_return_0("Last meal mutex failed"));
		}
		if (pthread_mutex_init(&(philosophers[i].mutex_meals_eaten_mutex), NULL) != 0)
		{	
			pthread_mutex_destroy(&(philosophers[i].last_meal));
			free(philosophers);
			philo_cleanup(dinner);
			return (error_and_return_0("meal eaten mutex failed"));
		}
		philosophers[i].alive = true;
		philosophers[i].dinner = dinner;
		philosophers[i].id = i + 1;
		philosophers[i].write = &dinner->write;
		philosopher_fork_behavior(i, philosophers, dinner);
		i++;
	}
	dinner->list_t_philos = philosophers;
	return (1);
}

void	philosopher_fork_behavior(int i, t_philo	*philosophers, t_dinner *dinner)
{
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
	return ;
}

int create_threads(t_dinner *dinner, t_philo *philosophers)
{
	int i;
	
	i = 0;
	dinner->philos_list_thread = malloc(sizeof(pthread_t) * dinner->philos);
	if (!dinner->philos_list_thread)
	{	
		total_cleanup(dinner);
		return (error_and_return_0("malloc philo threads failed")); 
	}
	while (i < dinner->philos)
	{
		if (pthread_create(&dinner->philos_list_thread[i], NULL, routine, &philosophers[i]) != 0)
			return(error_and_return_0("failed to create philo thread")); //in theory this is big bad
		i++;
	}
	if (pthread_create(&dinner->death_checker, NULL, the_watcher, dinner) != 0)
			return(error_and_return_0("failed to create  watcher thread")); //my wife
	dinner->start_time = get_time();
	setter_bool(&dinner->is_dinner_started, true, &dinner->dinner_start);
	i = 0;
	while (i < dinner->philos)
	{
		if (pthread_join(dinner->philos_list_thread[i], NULL) != 0)
			return(error_and_return_0("failed to join philo thread"));
		i++;
	}
	if (pthread_join(dinner->death_checker, NULL) != 0)
		return(error_and_return_0("failed to join watcher thread"));
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
