/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:15:45 by tfreydie          #+#    #+#             */
/*   Updated: 2023/11/21 13:34:38 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_copy;
	char	*dest_copy;

	src_copy = (char *)src;
	dest_copy = (char *)dest;
	i = 0;
	if (!(dest || src))
		return (NULL);
	while (i < n)
	{
		dest_copy[i] = src_copy[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	#include <stdio.h>
	char	source[] = "abcdefghij";
	char	dest[] = "0123456789";
	char	*result = (char *)ft_memcpy(NULL, NULL, 5);
	char	*OG_result = (char *)memcpy(NULL, NULL, 5);
	printf("%s\n", result);
	printf("%s\n", OG_result);

}*/
