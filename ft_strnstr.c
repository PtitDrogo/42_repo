/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:17:34 by tfreydie          #+#    #+#             */
/*   Updated: 2023/11/15 16:32:30 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[j] != '\0' && j < len)
	{
		i = 0;
		if (big[j] == little[i])
		{
			while (big[i + j] == little[i] && big[i + j] && (j + i) < len)
			{
				i++;
			}
			if (little[i] == '\0')
				return ((char *)(big + j));
		}
		j++;
	}
	return (NULL);
}

/*
//Compile with -lbsd
#include <bsd/string.h>
int	main(void)
{
	const char *big = "aaabcabcd";
	const char *little = "aabc";
	//size_t len = 8;
	#include <stdio.h>
	int	i;
	i = 0;
	char	*result = ft_strnstr(big, little, -1);
	char	*official_result = strnstr(big, little, -1);
	printf("%s\n", result);
	printf("%s\n", official_result);
}*/
