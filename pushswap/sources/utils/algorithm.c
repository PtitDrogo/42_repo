/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 05:08:37 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/14 19:21:22 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int push_to_median(t_node **roota, t_node **rootb, t_list *pushswap)
{
    t_node  *temp;
    int     median;
    int     number;
    
    median = pushswap->median;
    while((*roota)->next)
        (*roota) = (*roota)->next;
    printf("%p is current and %p is the address if of prev\n", (*roota), (*roota)->prev);
    while ((*roota))
    {
        number = (*roota)->number;
        temp = (*roota);
        (*roota) = (*roota)->prev;
        push(&temp, rootb, "pb");
        if (number > median) //< or > could be either really
            rotate(rootb, "rb");
    }
    return 0;
}

// int push_back_to_a(t_node **roota, t_node **rootb, t_list *pushswap)
// {
    
// }
