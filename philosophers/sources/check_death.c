/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:40:57 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/27 12:35:15 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Need a way to find out if a thread has passed the time to die limit;
//need a way to find out if we have eaten enough meals;
//Need to not print anything after the first time a philo die


// Have a thread monitoring everything at all time
// when a philo is dead, set the variable to is_dead variable to 1
// when printing, check if that variable is 1

int is_anybody_dead(t_dinner *dinner) //perfect function
{
    pthread_mutex_lock(&dinner->death);
    if (dinner->is_dead == true)
    {
        pthread_mutex_unlock(&dinner->death);
        return (1);
    }
    pthread_mutex_unlock(&dinner->death);
    return (0);
}


void    *death_check(void *arg)
{
    t_dinner    *dinner;
    t_philo     *philos;
    //I want to check with math is a philo should be dead of starvation
    //if thats the case, I change the variable of dinner to dead and write that philo id (i + 1 or just his id) died
    //this should make all write statement not write anymore and the code end at the beginning of next loop
    
    dinner = (t_dinner *)arg;
    philos = dinner->list_t_philos;
    // pthread_mutex_lock(&dinner->write);
    // printf("whats up i an death checker\n");
    // printf("number of philos is %li time to die %li\n", dinner->philos, dinner->time_to_die);
    // // printf("last meal time is %li\n", philos[i].last_meal_time);
    // pthread_mutex_unlock(&dinner->write);
    int i;

    long    time_since_last_meal; 

    while (1)
    {
        // usleep(500); This one fails the 800 200 200 test
        i = 0;
        while (i < dinner->philos)
        {
            time_since_last_meal = (get_current_time() - philos[i].start_time) - getter(&philos[i].last_meal_time, &philos[i].last_meal);
            pthread_mutex_lock(&philos[i].mutex_is_eating);
            if (time_since_last_meal > dinner->time_to_die && philos[i].is_eating == false) // > instead of >= for now
            {
                // pthread_mutex_lock(&dinner->write);
                // // printf("get_current_time value from this printf %li\n", get_current_time());
                // // printf("last meal time = %li\n", philos[i].last_meal_time);
                // // printf("time_since_last_meal = %li\n", time_since_last_meal);
                // pthread_mutex_unlock(&dinner->write);
                pthread_mutex_unlock(&philos[i].mutex_is_eating);
                mutex_write(&philos[i], "has died\n", philos[i].id);
                setter_bool(&dinner->is_dead, true, &dinner->death);
                return (NULL);
            }
            pthread_mutex_unlock(&philos[i].mutex_is_eating);
            i++;
        }
    }
    return (NULL);
}

int last_meal_check(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex_meals_eaten_mutex);
    if (philo->meals_eaten >= philo->dinner->meals_goal)
    {    
        pthread_mutex_unlock(&philo->mutex_meals_eaten_mutex);
        return (1);
    }
    pthread_mutex_unlock(&philo->mutex_meals_eaten_mutex);
    return (0);
}

