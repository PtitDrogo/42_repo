/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 03:21:27 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/20 14:56:07 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


t_node  *get_to_last_node(t_node *root)
{
    if (!root)
    {    
        printf("somehow fed NULL into get to last node\n"); //TODO REMOVE
        return NULL;
    }
    while(root->next)
        root = root->next;
    return (root);
}
