/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 05:08:37 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/22 18:37:50 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// int     nicememes(t_node **from, t_node **to, t_list *pushswap, int a_or_b);
// t_node *get_to_index(t_node *from, int len);
int     push_to_median(t_node **from, t_node **to, int median)
{
    t_node  *temp;
    int     median;
    int     number;
    int     list_len;
    
    list_len = listlen(*from);
    while((*from)->next)
        (*from) = (*from)->next;
    while ((*from)) //&& list_len > 3 in theory, but it leaks for some reason
    {
        number = (*from)->number;
        temp = (*from);
        (*from) = (*from)->prev;
        push(&temp, to); //obviously this is temporary
        printf("pb\n");
        if (number > median) //< or > could be either really
        {    
            rotate(to);
            printf("rb\n");
        }
        list_len--;
    }
    return 0;
}

// t_node *get_to_index(t_node *from, int len)
// {
//     int i;

//     i = 0;
//     while (i < len)
//     {
//         from = from->next;
//         i++;
//     }
//     return (from);
// }
// int nicememes(t_node **from, t_node **to, t_list *pushswap, int a_or_b)
// {
//     int max_size_list;
//     t_node  **start = malloc(sizeof(t_node *));
//     *start = malloc(sizeof(t_node ));

//     max_size_list = listlen(*from);
//     *start = get_to_index(*from, max_size_list);
//     push_to_median(start, to, pushswap, *start, a_or_b);
    
//     return (0);
// }

// t_node  *meme_findtarget_node(const t_node *targetless_node, const t_node *root_target_stack)
// {
// 	long long	node_number;
// 	long long	difference;
// 	long long	tmp_diff;
// 	t_node		*cursor;
// 	t_node		*target;
	
// 	difference = LONG_MAX;
// 	node_number = targetless_node->number;
// 	cursor = (t_node *)root_target_stack;
// 	while (cursor)
// 	{
// 		tmp_diff = (node_number - cursor->number);
// 		tmp_diff = tmp_diff * ((tmp_diff > 0) - (tmp_diff < 0));
// 		if (tmp_diff < difference)
// 		{    
// 			difference = tmp_diff;
// 			target = cursor; //maybe we will change the struct directly here well see
// 		}
// 		cursor = cursor->next;
// 	}
// 	return (target);
// }
