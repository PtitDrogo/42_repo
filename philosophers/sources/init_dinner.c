/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:58:49 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/03 14:49:42 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_dinner_mutexes(t_dinner *dinner);

int    init_dinner_variables(t_dinner *dinner, const char **argv, int argc)
{
	if (are_args_valid(argc, (char **)argv) == 0)
		return (0);
	dinner->philos = basic_safe_atol(argv[1]);
	dinner->time_to_die = basic_safe_atol(argv[2]);
	dinner->time_to_eat = basic_safe_atol(argv[3]);
	dinner->time_to_sleep = basic_safe_atol(argv[4]);
	if (argc == 6)
	{	
		dinner->meals_goal = basic_safe_atol(argv[5]);
		if (dinner->meals_goal == 0)
			return(0);
	}
	else
		dinner->meals_goal = -1;
	if (dinner->philos == ATOL_ERROR || dinner->time_to_die == ATOL_ERROR || dinner->time_to_eat == ATOL_ERROR || dinner->time_to_sleep == ATOL_ERROR || dinner->meals_goal == ATOL_ERROR)
		return(error_and_return_0("Numbers are way too big !"));
	init_dinner_mutexes(dinner);
	dinner->time_to_sleep *= 1000;
	dinner->time_to_eat *= 1000;
	dinner->is_dinner_started = false;
	return (1);
}
static int	init_dinner_mutexes(t_dinner *dinner)
{
	if (pthread_mutex_init(&dinner->write, NULL) != 0)
		return (error_and_return_0("failed to initialize mutex"));
	if (pthread_mutex_init(&dinner->death, NULL) != 0)
	{
        pthread_mutex_destroy(&dinner->write);
        return (error_and_return_0("failed to initialize mutex"));
    }
	if (pthread_mutex_init(&dinner->dinner_start, NULL) != 0)
    {
        pthread_mutex_destroy(&dinner->write);
        pthread_mutex_destroy(&dinner->death);
        return (error_and_return_0("failed to initialize mutex"));
    }
	return (1);
}

pthread_mutex_t *init_forks(long philos)
{
	pthread_mutex_t *forks;
    int status;
	int	i;

	i = -1;
    status = 1;
	forks = malloc(sizeof(pthread_mutex_t) * philos);
	if (!forks)
		return (error_and_return_NULL("Fork malloc failed"));
	while (++i < philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
        {    
            status = 0;
            break ;
        }
	}
    if (status == 0)
    {
        while (i-- > 0)
            pthread_mutex_destroy(&forks[i]);
        free (forks);
        return (error_and_return_NULL("Fork mutex failed"));
    }
	return (forks);
}
