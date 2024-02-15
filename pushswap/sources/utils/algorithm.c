/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:50:51 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/15 19:38:04 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node  *get_to_last_node(t_node *root);
// int initial_push_to_stackb(&roota, &rootb, pushswap)
// {
    
//     return 0;
// }

void    sort_3(t_node **roota)
{
    t_node  *current;
    int     a;
    int     b;
    int     c;

    if (is_sorted(*roota))
        return ;
    current = (*roota);
    a = (current->number);
    b = (current->next->number);
    c = (current->next->next->number);
    if (a < b && b > c && c < a)
        rotate(roota, "ra");
    else if (a > b && b < c && c < a)
        reverse_rotate(roota, "rra");
    else if (a < b && b > c && c > a)
        swap(*roota, "sa");
    else if (a > b)
    {
        swap(*roota, "sa");
        if (b > c)
            reverse_rotate(roota, "rra");
        else if (b < c)
            rotate(roota, "ra");
    }
}

int is_sorted(t_node *roota)
{
    int i;
    t_node  *current;

    current = roota;
    i = INT_MIN;
    
    while (current->next)
    {
        if (current->number < i)
            return (0);
        i = current->number;
        current = current->next; 
    }
    return (1);
}
