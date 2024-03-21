/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:40:57 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/21 19:40:20 by tfreydie         ###   ########.fr       */
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
    
    dinner = (t_dinner *)arg;
    philos = dinner->list_t_philos;
    pthread_mutex_lock(&dinner->write);
    printf("whats up i an death checker\n");
    pthread_mutex_unlock(&dinner->write);
    int i;
    int time_since_eat;
    // while (1)
    // {
    //     i = 0;
    //     while (i < dinner->philos)
    //     {
    //         pthread_mutex_lock(&dinner->list_t_philos[i].last_meal);
    //         time_since_eat = get_current_time() - dinner->list_t_philos[i].last_meal_time;
    //         pthread_mutex_unlock(&dinner->list_t_philos[i].last_meal);
    //         if (time_since_eat > dinner->time_to_die)
    //         {    
    //             pthread_mutex_lock(&dinner->death);
    //             dinner->is_dead = true;
    //             pthread_mutex_unlock(&dinner->death);
    //             pthread_mutex_lock(&dinner->write);
    //             printf("wesh jsuis printf et jvais kill le code direct tavu\n");
    //             printf("%i = time since eat | %li time to die", time_since_eat, dinner->time_to_die);
    //             pthread_mutex_unlock(&dinner->write);
    //             return NULL;
    //         }
    //         i++;
    //     }
    // }
    ////////SCIENCE/////////
    // while (1)
    // {
    //     i = 0;
    //     while (i < dinner->philos)
    //     {
    //         //I want to check with math is a philo should be dead of starvation
    //         //if thats the case, I change the variable of dinner to dead and write that philo id (i + 1 or just his id) died
    //         //this should make all write statement not write anymore and the code end at the beginning of next loop
    //         pthread_mutex_lock(&philos[i].last_meal);
    //         if ((get_current_time() - philos[i].last_meal_time) > dinner->time_to_die)
    //         {
    //             dinner->is_dead = true;
    //             mutex_write(&philos[i], "has died\n", philos[i].id);
    //         }
    //         pthread_mutex_unlock(&philos[i].last_meal);
    //         i++;
    //     }
    // }
    ///////////ENDSCIENCE//////////
    return (NULL);
}

// int last_meal_check(t_philo *philo)
// {
//     if ()
// }

