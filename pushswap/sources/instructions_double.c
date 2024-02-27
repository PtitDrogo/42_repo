/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 23:32:33 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/27 23:34:48 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ss(t_node **roota, t_node **rootb)
{
	if (swap(roota) == 0)
		return (0);
	if (swap(rootb) == 0)
		return (0);
	return (1);
}

int	rr(t_node **roota, t_node **rootb)
{
	if (rotate(roota) == 0)
		return (0);
	if (rotate(rootb) == 0)
		return (0);
	return (1);
}

int	rrr(t_node **roota, t_node **rootb)
{
	if (reverse_rotate(roota) == 0)
		return (0);
	if (reverse_rotate(rootb) == 0)
		return (0);
	return (1);
}
