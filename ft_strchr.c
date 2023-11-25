/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:54:16 by tfreydie          #+#    #+#             */
/*   Updated: 2023/11/23 19:46:18 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	int c = '\0';
	//int f = 'Z';
	const char *s = "\0";
	#include <stdio.h>
	printf("result = %s\n", ft_strchr(s, c));
	printf("result = %s\n", strchr(s, c));
}*/
