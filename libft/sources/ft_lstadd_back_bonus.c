/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:18:03 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/15 16:21:57 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list_libft **lst, t_list_libft *new)
{
	t_list_libft	*previous_last;

	if (!new)
		return ;
	if (lst)
	{
		if (!*lst)
			*lst = new;
		else
		{
			previous_last = ft_lstlast(*lst);
			previous_last->next = new;
		}
	}
}
