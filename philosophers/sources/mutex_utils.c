/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:07:15 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/04 16:14:56 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	increment(long *var, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	(*var)++;
	pthread_mutex_unlock(mutex);
	return ;
}

void	setter_bool(bool *var, bool new_value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*var = new_value;
	pthread_mutex_unlock(mutex);
	return ;
}

void	setter(long *var, long new_value, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	*var = new_value;
	pthread_mutex_unlock(mutex);
	return ;
}

bool	getter_bool(bool *var, pthread_mutex_t *mutex)
{
	bool	to_return;

	pthread_mutex_lock(mutex);
	to_return = *var;
	pthread_mutex_unlock(mutex);
	return (to_return);
}

long	getter(long *var, pthread_mutex_t *mutex)
{
	long	to_return;

	pthread_mutex_lock(mutex);
	to_return = *var;
	pthread_mutex_unlock(mutex);
	return (to_return);
}
