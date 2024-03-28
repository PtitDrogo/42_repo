/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:48:04 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/28 17:08:30 by tfreydie         ###   ########.fr       */
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
	pthread_mutex_lock(philo->fork_1);
	mutex_write(philo, "has taken a fork\n", philo->id);
	pthread_mutex_lock(philo->fork_2);
	mutex_write(philo, "has taken a fork\n", philo->id);

	mutex_write(philo, "is eating\n", philo->id);
	setter(&philo->last_meal_time, get_time() - philo->dinner->start_time,
		&philo->last_meal);
		
	usleep(philo->dinner->time_to_eat);
	
	pthread_mutex_unlock(philo->fork_2);
	pthread_mutex_unlock(philo->fork_1);
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
	if (philo->dinner->philos % 2 == 0)
        return ;
    if (((philo->dinner->time_to_eat * 2) - philo->dinner->time_to_sleep) > 0)
		usleep(((philo->dinner->time_to_eat * 2) - philo->dinner->time_to_sleep));
	return ;
}
