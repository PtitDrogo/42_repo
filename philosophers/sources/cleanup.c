/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:58:50 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/04 16:50:19 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	total_cleanup(t_dinner *dinner)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&dinner->write);
	pthread_mutex_destroy(&dinner->death);
	pthread_mutex_destroy(&dinner->dinner_start);
	while (i < dinner->philos)
	{
		pthread_mutex_destroy(&dinner->list_t_philos[i].last_meal);
		pthread_mutex_destroy(&dinner->list_t_philos[i].mutex_eaten);
		pthread_mutex_destroy(&dinner->forks[i]);
		i++;
	}
	free(dinner->thread);
	free(dinner->list_t_philos);
	free(dinner->forks);
}

void	philo_cleanup(t_dinner *dinner)
{
	int	i;

	pthread_mutex_destroy(&dinner->write);
	pthread_mutex_destroy(&dinner->death);
	pthread_mutex_destroy(&dinner->dinner_start);
	i = -1;
	while (++i < dinner->philos)
		pthread_mutex_destroy(&dinner->forks[i]);
	free(dinner->forks);
}

void	init_fork_cleanup(t_dinner *dinner)
{
	pthread_mutex_destroy(&dinner->write);
	pthread_mutex_destroy(&dinner->death);
	pthread_mutex_destroy(&dinner->dinner_start);
	return ;
}

int	cleanup_error(t_dinner *dinner, const char *err_msg)
{
	total_cleanup(dinner);
	return (error_and_return_0(err_msg));
}
