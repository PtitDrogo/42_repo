/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:07:12 by tfreydie          #+#    #+#             */
/*   Updated: 2023/12/05 16:52:39 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int	i;
	if (!s)
		return (0); //surement inutile
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
