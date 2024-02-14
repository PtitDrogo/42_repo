/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 05:08:37 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/14 20:42:18 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// int     nicememes(t_node **from, t_node **to, t_list *pushswap, int a_or_b);
// t_node *get_to_index(t_node *from, int len);
int     push_to_median(t_node **from, t_node **to, t_list *pushswap)
{
    t_node  *temp;
    int     median;
    int     number;
    int     list_len;
    
    list_len = listlen(*from);
    median = pushswap->median;
    while((*from)->next)
        (*from) = (*from)->next;
    while ((*from) && list_len >= 3) //&& list_len > 3 in theory, but it leaks for some reason
    {
        number = (*from)->number;
        temp = (*from);
        (*from) = (*from)->prev;
        push(&temp, to, "pb"); //obviously this is temporary
        if (number > median) //< or > could be either really
            rotate(to, "rb");
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

