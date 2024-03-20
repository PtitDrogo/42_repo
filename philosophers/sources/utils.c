/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:43:58 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/20 14:46:03 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	increment(long *var, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	(*var)++;
    ft_printf("var is = %i\n", (int) *var); //obviously i need a write mutex
	pthread_mutex_unlock(mutex);
    return ;
}

void	setter(long *var, long new_value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*var = new_value;
	pthread_mutex_unlock(mutex);
	return ;
}

long	getter(long *var, pthread_mutex_t *mutex)
{
	long	to_return;

	pthread_mutex_lock(mutex);
	to_return = *var;
	pthread_mutex_unlock(mutex);
	return (to_return);
}

void	mutex_write(t_philo *philo, char *to_print, int id)
{
	long time;
	
	pthread_mutex_lock(philo->write);
	time = get_current_time() - philo->start_time; //TODO define start time
	printf("%li %i %s", time, id, to_print);
	pthread_mutex_unlock(philo->write);
	return ;
}

long get_current_time(void)
{
	struct timeval	time;

	long	current_time;
	
	if (gettimeofday(&time, NULL) == -1)
		perror("error getting time"); //TODO update and kill properly
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	// printf("in get current time = %li\n", current_time);
	return (current_time);
}

	// ////////////test init fork/////
	// printf("philos = %li\n", dinner.philos);
	// for (int i = 0; i < dinner.philos; i++)
	// {
	// 	printf("hi\n");
	// 	printf("fork %i = %p\n", i, &forks[i]);
	// }

	// ////////////////////////////////	
	// ////////////test init fork/////
	// for (int i = 0; i < dinner.philos; i++)
	// {
	// 	printf("philo %i has left fork %p and right fork %p\n", i, philosophers[i].left_fork, philosophers[i].right_fork);
	// }
	// ////////////////////////////////
