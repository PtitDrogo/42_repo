/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:48:04 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/20 15:25:28 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *philo);
static void    ft_sleep(t_philo *philo);
static void    think(t_philo *philo);

void	philo_grindset(t_philo *philo)
{
	while (1)
	{
		eat(philo);
		ft_sleep(philo);
		think(philo);
    }
}


static void	eat(t_philo *philo)
{
    pthread_mutex_lock(philo->left_fork);
    mutex_write(philo, "has taken a fork\n", philo->id);
    pthread_mutex_lock(philo->right_fork);
    mutex_write(philo, "has taken a fork\n", philo->id); //could sync msgs idk
    mutex_write(philo, "is eating\n", philo->id);
    usleep(philo->dinner->time_to_eat * 1000);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    (philo->meals_eaten)++; //maybe mutex this for checker thread
    return ;
}



static void    ft_sleep(t_philo *philo)
{
    mutex_write(philo, "is sleeping\n", philo->id);
	usleep(philo->dinner->time_to_sleep * 1000); //replace this with proper time
	return ;
}



static void    think(t_philo *philo)
{
    mutex_write(philo, "is thinking\n", philo->id);
	return ;
}