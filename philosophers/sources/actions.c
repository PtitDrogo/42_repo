/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:48:04 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/27 16:42:40 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		eat(t_philo *philo);
static void		snooze(t_philo *philo);
static void		think(t_philo *philo);

void	philo_grindset(t_philo *philo)
{
	philo->meals_eaten = 0;
	while (is_anybody_dead(philo->dinner) == 0)
	{
		eat(philo);
		snooze(philo);
		think(philo);
	}
	return ;
}

static void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		mutex_write(philo, "has taken a fork\n", philo->id);
		pthread_mutex_lock(philo->right_fork);
		mutex_write(philo, "has taken a fork\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		mutex_write(philo, "has taken a fork\n", philo->id);
		pthread_mutex_lock(philo->left_fork);
		mutex_write(philo, "has taken a fork\n", philo->id);
	}
	setter_bool(&philo->is_eating, true, &philo->mutex_is_eating);
	mutex_write(philo, "is eating\n", philo->id);
	setter(&philo->last_meal_time, get_time() - philo->dinner->start_time,
		&philo->last_meal);
	usleep(philo->dinner->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	setter_bool(&philo->is_eating, false, &philo->mutex_is_eating);
	increment(&philo->meals_eaten, &philo->mutex_meals_eaten_mutex);
	return ;
}

static void	snooze(t_philo *philo)
{
	mutex_write(philo, "is sleeping\n", philo->id);
	usleep(philo->dinner->time_to_sleep);
	return ;
}

static void	think(t_philo *philo)
{
	mutex_write(philo, "is thinking\n", philo->id);
	return ;
}
