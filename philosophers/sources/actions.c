/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:48:04 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/20 18:57:34 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *philo);
static void    ft_sleep(t_philo *philo);
static void    think(t_philo *philo);

void	philo_grindset(t_philo *philo)
{
    philo->meals_eaten = 0;
    while (is_anybody_dead(philo->dinner) == 0 && philo->meals_eaten < 5) // obviously temporary
	{
		eat(philo);
		ft_sleep(philo);
		think(philo);
    }
    mutex_write(philo, "HMMM j'ai bien vecu adieu\n", philo->id + 1);
    return ;
}
static void	eat(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {    
        pthread_mutex_lock(philo->left_fork);
        mutex_write(philo, "has taken a left fork\n", philo->id + 1);
        pthread_mutex_lock(philo->right_fork);
        mutex_write(philo, "has taken a right fork\n", philo->id + 1); //could sync msgs idk
        mutex_write(philo, "is eating\n", philo->id);
    }
    else
    {    
        pthread_mutex_lock(philo->right_fork);
        mutex_write(philo, "has taken a right fork\n", philo->id + 1); //could sync msgs idk
        pthread_mutex_lock(philo->left_fork);
        mutex_write(philo, "has taken a left fork\n", philo->id + 1);
        mutex_write(philo, "is eating\n", philo->id);
    }
    usleep(philo->dinner->time_to_eat * 1000);
    // philo->last_meal_time = get_current_time() - philo->start_time;
    // setter(long *var, long new_value, pthread_mutex_t *)
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    (philo->meals_eaten)++; //maybe mutex this for checker thread
    return ;
}



static void    ft_sleep(t_philo *philo)
{
    mutex_write(philo, "is sleeping\n", philo->id + 1);
	usleep(philo->dinner->time_to_sleep * 1000); //replace this with proper time
	return ;
}



static void    think(t_philo *philo)
{
    mutex_write(philo, "is thinking\n", philo->id + 1);
	return ;
}