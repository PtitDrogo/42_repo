/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:48:04 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/22 17:59:48 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *philo);
static void    snooze(t_philo *philo);
static void    think(t_philo *philo);

void	philo_grindset(t_philo *philo)
{
    philo->meals_eaten = 0;
    while (is_anybody_dead(philo->dinner) == 0) // will be max amount of meals later |||&& philo->meals_eaten < 4
	{
		eat(philo);
		snooze(philo);
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
    pthread_mutex_lock(&philo->mutex_is_eating);
    philo->is_eating = true;
    pthread_mutex_unlock(&philo->mutex_is_eating);
    usleep(philo->dinner->time_to_eat * 1000);
    //uncommenting this makes philosophers time travel sometimes
    /////////////////////////////////TEST ZONE
    pthread_mutex_lock(&philo->last_meal);
	philo->last_meal_time = get_current_time() - philo->start_time;
    // pthread_mutex_lock(philo->write);
    // printf("in eat philo %i last meal time is %li\n", philo->id, philo->last_meal_time);
    // pthread_mutex_unlock(philo->write);
    pthread_mutex_unlock(&philo->last_meal);
    
    pthread_mutex_lock(&philo->mutex_is_eating);
    philo->is_eating = false;
    pthread_mutex_unlock(&philo->mutex_is_eating);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    // (philo->meals_eaten)++; // mutex this for checker thread later
    increment(&philo->meals_eaten, &philo->mutex_meals_eaten_mutex); //with mutex
    return ;
}



static void    snooze(t_philo *philo)
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