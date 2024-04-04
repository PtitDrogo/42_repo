/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:43:58 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/04 16:56:39 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_write(t_philo *philo, char *to_print, int id)
{
	long	time;

	pthread_mutex_lock(philo->write);
	time = get_time() - philo->dinner->start_time;
	if (is_anybody_dead(philo->dinner) == 0)
		printf("%li %i %s", time, id, to_print);
	pthread_mutex_unlock(philo->write);
	return ;
}

long	get_time(void)
{
	struct timeval	time;
	long			current_time;

	if (gettimeofday(&time, NULL) == -1)
		error_and_return_0("Error getting time");
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}

int	is_anybody_dead(t_dinner *dinner)
{
	if (getter_bool(&dinner->is_dead, &dinner->death) == true)
		return (1);
	return (0);
}

int	ft_usleep(long milliseconds)
{
	long	start;

	milliseconds /= 1000;
	start = get_time();
	while ((get_time() - start) < milliseconds)
	{
		usleep(500);
	}
	return (0);
}
