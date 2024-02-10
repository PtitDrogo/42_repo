/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 05:08:37 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/10 06:30:00 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int push_to_median(t_node **roota, t_node **rootb)
{
    t_node *current;
    
    current = (*roota);
    //this code is complete ass need to redo everything
    // with ** otherwise shit wont work
    while (current->next)
    {
        push(current, rootb, "pb");
        if (current->number > (*roota)->median_of_list)
            rotate(rootb, "rb");
    }
    // push(current, rootb, "pb");
    // if (current->number > (*roota)->median_of_list)
    //         rotate(rootb, "rb");
    return 0;
}
