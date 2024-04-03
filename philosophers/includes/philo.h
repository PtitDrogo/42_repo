/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:36:07 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/03 15:20:51 by tfreydie         ###   ########.fr       */
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
#include <limits.h>

///------------------------Structs------------------------///
typedef struct s_dinner t_dinner;
typedef struct s_philo 
{
    bool        alive;
    int         id;

    
    // bool            is_eating;
    // pthread_mutex_t mutex_is_eating;
    
    long            meals_eaten;
    pthread_mutex_t mutex_meals_eaten_mutex;
    
    long            last_meal_time;
    pthread_mutex_t last_meal;

    t_dinner        *dinner;
    pthread_mutex_t *fork_1;
    pthread_mutex_t *fork_2;
    pthread_mutex_t *write;

} t_philo;

typedef struct s_dinner
{
    pthread_t       *philos_list_thread;
    pthread_t       death_checker;
    
    t_philo         *list_t_philos;
    
    pthread_mutex_t write;
    pthread_mutex_t death;

    pthread_mutex_t *forks;
    
    bool        is_dead;
    long        time_to_die;
    long        time_to_eat;
    long        time_to_sleep;
    long        philos;
    long        start_time;

    pthread_mutex_t dinner_start;
    bool            is_dinner_started;
    
    long            meals_goal;
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
///------------------------Define------------------------///

#define ATOL_ERROR -42


///------------------------Functions------------------------///


long	getter(long *var, pthread_mutex_t *mutex);
bool	getter_bool(bool *var, pthread_mutex_t *mutex);
void	setter_bool(bool *var, bool new_value, pthread_mutex_t *mutex);
void	setter(long *var, long new_value, pthread_mutex_t *mutex);
void	increment(long *var, pthread_mutex_t *mutex);
long    get_time(void);
void	mutex_write(t_philo *philo, char *to_print, int id);
int    error_and_return_0(const char *err_msg);
void *error_and_return_NULL(const char *err_msg);


int	    ft_printf(const char *text, ...);

void	philo_grindset(t_philo *philo);
void    *the_watcher(void *arg);
int	is_anybody_dead(t_dinner *dinner);
int are_args_valid(int argc, char **args);
int    init_dinner_variables(t_dinner *dinner, const char **argv, int argc);

long	basic_safe_atol(const char *nptr);


int	ft_usleep(long milliseconds);
void *routine(void *arg);