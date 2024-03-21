/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:48:04 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/21 19:43:16 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *philo);
static void    ft_sleep(t_philo *philo);
static void    think(t_philo *philo);

void	philo_grindset(t_philo *philo)
{
    philo->meals_eaten = 0;
    while (is_anybody_dead(philo->dinner) == 0 && philo->meals_eaten < 3) // will be max amount of meals later
	{
		eat(philo);
		ft_sleep(philo);
		think(philo);
    }
    mutex_write(philo, "HMMM j'ai bien vecu adieu\n", philo->id);
    return ;
}
static void	eat(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {    
        pthread_mutex_lock(philo->left_fork);
        mutex_write(philo, "has taken a left fork\n", philo->id);
        pthread_mutex_lock(philo->right_fork);
        mutex_write(philo, "has taken a right fork\n", philo->id); //could sync msgs idk
        mutex_write(philo, "is eating\n", philo->id);
    }
    else
    {    
        pthread_mutex_lock(philo->right_fork);
        mutex_write(philo, "has taken a right fork\n", philo->id); //could sync msgs idk
        pthread_mutex_lock(philo->left_fork);
        mutex_write(philo, "has taken a left fork\n", philo->id);
        mutex_write(philo, "is eating\n", philo->id);
    }
    usleep(philo->dinner->time_to_eat * 1000);
    // /////////////////////////////////TEST ZONE
    pthread_mutex_lock(&philo->last_meal);
	philo->last_meal_time = get_current_time() - philo->start_time;
    pthread_mutex_unlock(&philo->last_meal);
    pthread_mutex_lock(philo->write);
    printf("philo %i last meal time is %li\n", philo->id, philo->last_meal_time);
    pthread_mutex_unlock(philo->write);
    // /////////////////////////////////

    
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