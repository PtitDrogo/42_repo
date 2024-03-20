/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:40:57 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/20 18:59:42 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//Need a way to find out if a thread has passed the time to die limit;
//need a way to find out if we have eaten enough meals;
//Need to not print anything after the first time a philo die


// Have a thread monitoring everything at all time
// when a philo is dead, set the variable to is_dead variable to 1
// when printing, check if that variable is 1

int is_anybody_dead(t_dinner *dinner)
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

    dinner = (t_dinner *)arg;
    /////Todelete//
    pthread_mutex_lock(&dinner->write);
    printf("whats up i an death checker\n");
    pthread_mutex_unlock(&dinner->write);
    ///Todelete/////
    
    /////////////////////////////////
    //Actual work now ///
    /////////////////////
    //check death and check meals eaten
    // while ()


    
    return (NULL);
}

// int last_meal_check(t_philo *philo)
// {
//     if ()
// }

