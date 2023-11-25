/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:14:56 by tfreydie          #+#    #+#             */
/*   Updated: 2023/11/17 15:41:25 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*copy;

	copy = (char *)s;
	i = 0;
	while (i < n)
	{
		copy[i] = c;
		i++;
	}
	return (s);
}

/*
int	main(void)
{
	#include <unistd.h>
	#include <stdio.h>
	int	i = 0;
	
	char	pointer[] = "test";
	ft_memset(pointer, '5', 3);
	
	while (pointer[i])
	{
		write(1,&pointer[i], 1);
		i++;
	}	
	printf("\n");
}*/
