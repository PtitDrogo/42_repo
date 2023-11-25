/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:19:40 by tfreydie          #+#    #+#             */
/*   Updated: 2023/11/23 15:50:24 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z'));
}
/*
int	main(void)
{
	int	result1;
	int	result2;
	result1 = ft_isalpha('/');
	result2 = ft_isalpha('i');
	#include <stdio.h>
	printf("%i, %i\n", result1, result2);
}*/
