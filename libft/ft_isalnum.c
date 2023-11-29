/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:42:31 by tfreydie          #+#    #+#             */
/*   Updated: 2023/11/23 15:50:10 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
/*
int	main(void)
{
	int	result1;
	int	result2;
	result1 = ft_isalnum('B');
	result2 = ft_isalnum('7');
	#include <stdio.h>
	printf("%i, %i\n", result1, result2);
}*/
