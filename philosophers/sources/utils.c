/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:43:58 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/27 11:38:48 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	increment(long *var, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	(*var)++;
	pthread_mutex_unlock(mutex);
    return ;
}

void	setter_bool(bool *var, bool new_value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*var = new_value;
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

bool	getter_bool(bool *var, pthread_mutex_t *mutex)
{
	bool	to_return;

	pthread_mutex_lock(mutex);
	to_return = *var;
	pthread_mutex_unlock(mutex);
	return (to_return);
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
	time = get_current_time() - philo->start_time; //start_time is always the same
	if (is_anybody_dead(philo->dinner) == 0)
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

// int	usleep(long milliseconds)
// {
// 	long	start;

// 	start = get_current_time();
// 	while ((get_current_time() - start) < milliseconds)
// 	{	
// 		usleep(500);
// 		write(1, "hi\n", 3);
// 	}
// 	return (0);
// }
