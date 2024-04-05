/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:58:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/05 11:35:30 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		create_threads(t_dinner *dinner, t_philo *philosophers);
static int		init_all(t_dinner *dinner, int argc, char const **argv);

int	main(int argc, char const *argv[])
{
	t_dinner	dinner;

	memset(&dinner, 0, sizeof(t_dinner));
	if (init_all(&dinner, argc, argv) == 0)
		return (1);
	if (dinner.philos == 1)
	{
		if (lonely_philosopher(&dinner) == 0)
			return (1);
	}
	else
	{
		if (create_threads(&dinner, dinner.list_t_philos) == 0)
			return (1);
	}
	return (0);
}

static int	init_all(t_dinner *dinner, int argc, char const **argv)
{
	if (init_dinner_variables(dinner, argv, argc) == 0)
		return (0);
	if (init_forks(dinner) == 0)
		return (0);
	if (init_philosophers(dinner) == 0)
		return (0);
	return (1);
}

static int	create_threads(t_dinner *dinner, t_philo *philosophers)
{
	int	i;

	i = -1;
	dinner->thread = malloc(sizeof(pthread_t) * dinner->philos);
	if (!dinner->thread)
		return (cleanup_error(dinner, "malloc philo threads failed"));
	if (pthread_create(&dinner->death_checker, NULL, the_watcher, dinner) != 0)
		return (cleanup_error(dinner, "failed to create watcher thread"));
	while (++i < dinner->philos && dinner->error == false)
	{
		if (pthread_create(&dinner->thread[i], NULL, routine, &philosophers[i]))
			dinner->error = true;
	}
	if (dinner->error == true)
		error_and_return_0("failed to create thread");
	dinner->start_time = get_time();
	setter_bool(&dinner->is_dinner_started, true, &dinner->dinner_start);
	while (--i >= 0)
	{
		if (pthread_join(dinner->thread[i], NULL) != 0)
			return (cleanup_error(dinner, "failed to join thread"));
	}
	if (pthread_join(dinner->death_checker, NULL) != 0)
		return (cleanup_error(dinner, "failed to join thread"));
	return (total_cleanup(dinner), dinner->error == false);
}
