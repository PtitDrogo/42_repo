/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:40:19 by tfreydie          #+#    #+#             */
/*   Updated: 2023/11/08 14:29:14 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/*
int	main(void)
{
	#include <stdio.h>
	char	test[] = "jesuisuntest";
	size_t n = 5;
	ft_bzero(test, n);
	//bzero(test, n);
	printf("%s\n", test);
	//copy colle dans python tutor ca marche;
}*/
