/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:36:07 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/20 18:57:18 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


///------------------------Includes------------------------///
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <sys/time.h>

///------------------------Structs------------------------///
typedef struct s_dinner t_dinner;
typedef struct s_philo 
{
    bool        alive;
    int         meals_eaten;
    int         id;
    long        start_time;
    long        last_meal_time;

    t_dinner    *dinner;
    pthread_mutex_t last_meal;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *write;
} t_philo;

typedef struct s_dinner
{
    pthread_t       *philos_list;
    pthread_mutex_t mutex; //todo fix this random var name
    pthread_mutex_t write;
    pthread_mutex_t death;
    pthread_t       death_checker;

    bool        is_dead;
    long        time_to_die;
    long        time_to_eat;
    long        time_to_sleep;
    long        philos;
    // long        synchronise;
    long        min_meals;
} t_dinner;

/*
    - I generate all philosophers with p_thread;
    - I generate all forks its just an int idk;
    - I store dinner variables;
    - I generate a mutex for each forks
    - I join all p_thread at the end or in case of error(?)
    - I synchronise all threads (need to ask how again)
    - timer start;
    - all even philosophers grabs forks next to them and eat;
    - after they are done eating they sleep and after they are done sleeping they think;
    - the philosophers next to them then grab the forks and eat;
    - an extra thread checks
    - once one of the exit conditions is met, end dinner;
*/
/*
    - Make an extra thread that will check if other philosophers are dead;
    - I guess it just loops over and over the list of philo and their alive status;
*/


///------------------------Functions------------------------///


long	getter(long *var, pthread_mutex_t *mutex);
void	setter(long *var, long new_value, pthread_mutex_t *mutex);
void	increment(long *var, pthread_mutex_t *mutex);
long    get_current_time(void);
void	mutex_write(t_philo *philo, char *to_print, int id);



int	    ft_printf(const char *text, ...);


void	philo_grindset(t_philo *philo);
int     is_anybody_dead(t_dinner *dinner);
void    *death_check(void *arg);