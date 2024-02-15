/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:52:42 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/15 16:21:57 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_libft	*ft_lstmap(t_list_libft *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*new_content;
	t_list_libft	*new_node;
	t_list_libft	*new_lst;

	if (!lst || !(*f) || !(*del))
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		new_content = (*f)(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			(*del)(new_content);
			ft_lstclear(&new_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
