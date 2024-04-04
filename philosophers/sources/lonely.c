/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:29:52 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/04 16:48:50 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*lonely_routine(void *arg)
{
	t_dinner	*dinner;

	dinner = (t_dinner *)arg;
	printf("0 1 has taken a fork\n");
	ft_usleep(dinner->time_to_die);
	printf("%li 1 philosopher died\n", dinner->time_to_die);
	total_cleanup(dinner);
	return (NULL);
}

int	lonely_philosopher(t_dinner *dinner)
{
	pthread_t	philo;

	if (pthread_create(&philo, NULL, lonely_routine, (void *)dinner) != 0)
		return (cleanup_error(dinner, "failed to create lonely thread"));
	if (pthread_join(philo, NULL) != 0)
		return (cleanup_error(dinner, "failed to join lonely thread"));
	return (1);
}
