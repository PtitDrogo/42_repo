/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:38:39 by tfreydie          #+#    #+#             */
/*   Updated: 2024/04/03 15:19:28 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
static int	ft_strlen(const char *s);

int    error_and_return_0(const char *err_msg)
{
	if (!err_msg)
		return (0);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
	return (0);
}

void *error_and_return_NULL(const char *err_msg)
{
	if (!err_msg)
		return (0);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
	return (NULL);
}
static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
		i++;
	return (i);
}


// void    cleanup(t_dinner *dinner)
// {
// 	pthread_mutex_destroy(&dinner->write);
// 	pthread_mutex_destroy(&dinner->death);
// 	pthread_mutex_destroy(&dinner->dinner_start);
// 	i = -1;
// 	while (++i < dinner->philos)
// 		pthread_mutex_destroy(&forks[i]);
// 	free(forks);
// 	return (error_and_return_0("Philo malloc failed"));
	
// }