/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptitdrogo <ptitdrogo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:40:57 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/01 20:57:23 by ptitdrogo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		last_meal_check(t_philo *philo);
static bool		did_all_eat(t_dinner *dinner, t_philo *philos);
static bool		death_check_for_real(t_dinner *dinner, t_philo *philos);
int	calculate_philo_death(t_philo *philo, t_dinner *dinner);

void	*the_watcher(void *arg)
{
	t_dinner	*dinner;
	t_philo		*philos;

	dinner = (t_dinner *)arg;
	philos = dinner->list_t_philos;
	while (!getter_bool(&dinner->is_dinner_started, &dinner->dinner_start))
	{
		ft_usleep(500);
	}
	while (1)
	{
		if (death_check_for_real(dinner, philos) == true)
			return (NULL);
		if (did_all_eat(dinner, philos) == true)
			return (NULL);
	}
	return (NULL);
}

static bool	death_check_for_real(t_dinner *dinner, t_philo *philos)
{
	int			i;
	// long		time_since_last_meal;
	long		time;
	// long		current_time;

	i = 0;
	while (i < dinner->philos)
	{
		// time_since_last_meal = (get_time() - dinner->start_time) - getter(&philos[i].last_meal_time, &philos[i].last_meal);
		// ft_usleep(5000);
		// mutex_write(&philos[i], "im looking at philo 5", i + 1)
		//get_time() - dinner->start_time - getter(&philos[i].last_meal_time, &philos[i].last_meal) > dinner->time_to_die
		// if (i == 0)
		// 	printf("%li\n", get_time());
		// if (i == 1)
		// {
		// 	time = get_time();
		// 	printf("time %li start time %li last meal time %li time to die %li\n", time, dinner->start_time, philos[i].last_meal_time, dinner->time_to_die);
		// }
		if (calculate_philo_death(&philos[i], dinner))
		{
			setter_bool(&dinner->is_dead, true, &dinner->death);
			time = get_time() - philos->dinner->start_time;
			pthread_mutex_lock(philos->write);
			printf("%li %i %s", time, philos[i].id, "died\n");
			pthread_mutex_unlock(philos->write);
			return (true);
		}
		i++;
	}
	return (false);
}

int	calculate_philo_death(t_philo *philo, t_dinner *dinner)
{
	pthread_mutex_lock(&philo->last_meal);
	long time = get_time();
	if (time - dinner->start_time - philo->last_meal_time > dinner->time_to_die)
	{	
		printf("time %li start time %li last meal time %li time to die %li\n", time, dinner->start_time, philo->last_meal_time, dinner->time_to_die);
		printf("time - start time = %li\n", time - dinner->start_time);
		pthread_mutex_unlock(&philo->last_meal);
		printf("dead\n");
		return (1);
	}
	// printf("not dead\n");
	pthread_mutex_unlock(&philo->last_meal);
	return (0);
}

static bool	did_all_eat(t_dinner *dinner, t_philo *philos)
{
	int	philo_full;
	int	i;

	i = 0;
	philo_full = 0;
	if (dinner->meals_goal == -1)
		return (false);
	while (i < dinner->philos)
	{
		if (last_meal_check(&philos[i]) == 1)
			philo_full++;
		i++;
	}
	if (philo_full == dinner->philos)
	{
		setter_bool(&dinner->is_dead, true, &dinner->death);
		return (true);
	}
	return (false);
}

static int	last_meal_check(t_philo *philo)
{
	if (getter(&philo->meals_eaten, &philo->mutex_meals_eaten_mutex)
		>= philo->dinner->meals_goal)
		return (1);
	return (0);
}
