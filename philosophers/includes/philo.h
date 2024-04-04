/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:36:07 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/04 17:23:34 by tfreydie         ###   ########.fr       */
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
typedef struct s_dinner	t_dinner;
typedef struct s_philo
{
	bool			alive;
	int				id;

	long			meals_eaten;
	pthread_mutex_t	mutex_eaten;

	long			last_meal_time;
	pthread_mutex_t	last_meal;

	t_dinner		*dinner;
	pthread_mutex_t	*fork_1;
	pthread_mutex_t	*fork_2;
	pthread_mutex_t	*write;

}	t_philo;

typedef struct s_dinner
{
	pthread_t		*thread;
	pthread_t		death_checker;

	t_philo			*list_t_philos;

	pthread_mutex_t	write;
	pthread_mutex_t	death;

	pthread_mutex_t	*forks;

	bool			is_dead;
	bool			error;

	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			philos;
	long			start_time;

	pthread_mutex_t	dinner_start;
	bool			is_dinner_started;

	long			meals_goal;
}	t_dinner;

///------------------------Define------------------------///

#define ATOL_ERROR -42

///------------------------Functions------------------------///

//mutex_utils
long	getter(long *var, pthread_mutex_t *mutex);
bool	getter_bool(bool *var, pthread_mutex_t *mutex);
void	setter_bool(bool *var, bool new_value, pthread_mutex_t *mutex);
void	setter(long *var, long new_value, pthread_mutex_t *mutex);
void	increment(long *var, pthread_mutex_t *mutex);

//utils
long	get_time(void);
void	mutex_write(t_philo *philo, char *to_print, int id);
int		error_and_return_0(const char *err_msg);
int		is_anybody_dead(t_dinner *dinner);
int		ft_usleep(long milliseconds);

//parsing
int		are_args_valid(int argc, char **args);
long	basic_safe_atol(const char *nptr);

//routines
void	*the_watcher(void *arg);
void	*routine(void *arg);

//init
int		init_philosophers(t_dinner *dinner);
int		init_forks(t_dinner *dinner);
int		init_dinner_variables(t_dinner *dinner, const char **argv, int argc);

//cleanup
void	total_cleanup(t_dinner *dinner);
void	philo_cleanup(t_dinner *dinner);
void	init_fork_cleanup(t_dinner *dinner);
int		cleanup_error(t_dinner *dinner, const char *err_msg);

//lonely
void	*lonely_routine(void *arg);
int		lonely_philosopher(t_dinner *dinner);
