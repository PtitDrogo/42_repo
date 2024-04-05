/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:00:09 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/05 11:32:07 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philo_vars(t_dinner *dinner, int i);
static int	safe_philo_mutex_init(t_philo	*philosophers, t_dinner *dinner);
static void	fork_behavior(int i, t_philo	*philosophers, t_dinner *dinner);

int	init_philosophers(t_dinner *dinner)
{
	int	i;

	dinner->list_t_philos = malloc(sizeof(t_philo) * dinner->philos);
	if (!dinner->list_t_philos)
	{
		philo_cleanup(dinner);
		return (error_and_return_0("Philo malloc failed"));
	}
	i = -1;
	while (++i < dinner->philos)
	{
		memset(&dinner->list_t_philos[i], 0, sizeof(t_philo));
		if (safe_philo_mutex_init(&dinner->list_t_philos[i], dinner) == 0)
		{
			while (i-- > 0)
			{
				pthread_mutex_destroy(&dinner->list_t_philos[i].mutex_eaten);
				pthread_mutex_destroy(&dinner->list_t_philos[i].last_meal);
			}
			return (error_and_return_0("Philosopher mutex failed"));
		}
		set_philo_vars(dinner, i);
		fork_behavior(i, dinner->list_t_philos, dinner);
	}
	return (1);
}

static void	set_philo_vars(t_dinner *dinner, int i)
{
	dinner->list_t_philos[i].alive = true;
	dinner->list_t_philos[i].dinner = dinner;
	dinner->list_t_philos[i].id = i + 1;
	dinner->list_t_philos[i].write = &dinner->write;
	return ;
}

int	safe_philo_mutex_init(t_philo	*philosophers, t_dinner *dinner)
{
	if (pthread_mutex_init(&(philosophers->last_meal), NULL) != 0)
	{
		free(philosophers);
		philo_cleanup(dinner);
		return (0);
	}
	if (pthread_mutex_init(&(philosophers->mutex_eaten), NULL) != 0)
	{
		pthread_mutex_destroy(&(philosophers->last_meal));
		free(philosophers);
		philo_cleanup(dinner);
		return (0);
	}
	return (1);
}

void	fork_behavior(int i, t_philo	*philosophers, t_dinner *dinner)
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
