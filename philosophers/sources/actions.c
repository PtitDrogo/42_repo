/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:48:04 by tfreydie          #+#    #+#             */
/*   Updated: 2024/07/11 01:18:14 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		eat(t_philo *philo);
static void		snooze(t_philo *philo);
static void		think(t_philo *philo);
static void		philo_grindset(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (getter_bool(&philo->dinner->is_dinner_started,
			&philo->dinner->dinner_start) == false)
	{
		ft_usleep(500);
	}
	if (philo->dinner->error == true)
		return (NULL);
	philo_grindset(philo);
	return (NULL);
}

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
	ft_usleep(philo->dinner->time_to_eat);
	pthread_mutex_unlock(philo->fork_2);
	pthread_mutex_unlock(philo->fork_1);
	increment(&philo->meals_eaten, &philo->mutex_eaten);
	return ;
}

static void	snooze(t_philo *philo)
{
	mutex_write(philo, "is sleeping\n", philo->id);
	ft_usleep(philo->dinner->time_to_sleep);
	return ;
}

static void	think(t_philo *philo)
{
	mutex_write(philo, "is thinking\n", philo->id);
	if (philo->dinner->philos % 2 == 0)
		return ; //GIGANTESQUE FUN FACT CA DOIT ETRE TOUT LE TEMPS
	if (((philo->dinner->time_to_eat * 2) - philo->dinner->time_to_sleep) > 0)
		ft_usleep(((philo->dinner->time_to_eat * 2)
				- philo->dinner->time_to_sleep));
	return ;
}
