/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:43:58 by tfreydie          #+#    #+#             */
/*   Updated: 2024/03/18 17:07:08 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	increment(long *var, pthread_mutex_t *mutex)
{
	pthread_mutex_lock(mutex);
	(*var)++;
    ft_printf("var is = %i\n", (int) *var);
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

long	getter(long *var, pthread_mutex_t *mutex)
{
	long	to_return;

	pthread_mutex_lock(mutex);
	to_return = *var;
	pthread_mutex_unlock(mutex);
	return (to_return);
}