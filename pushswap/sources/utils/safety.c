/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptitdrogo <ptitdrogo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:59:58 by ptitdrogo         #+#    #+#             */
/*   Updated: 2024/02/25 02:15:56 by ptitdrogo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// typedef void (*execfunction_tworoot)(t_node **, t_node**);
// typedef void (*execfunction_oneroot)(t_node **);

int    safe_exec_two_stack(execfunction_tworoot instruction, t_node ** from_root, t_node **to_root, char *to_print)
{
    instruction(from_root, to_root);
    if (write(1, to_print, ft_strlen(to_print)) == -1)
    {
        deallocate(*from_root);
        deallocate(*to_root);
        exit(EXIT_FAILURE);
    }
    return (1);
}

int    safe_exec_one_stack(execfunction_oneroot instruction, t_node **root, t_node **root_to_free, char *to_print)
{
    instruction(root);
    if (write(1, to_print, ft_strlen(to_print)) == -1)
    {
        deallocate(*root);
        deallocate(*root_to_free);
        exit(EXIT_FAILURE);
    }
    return (1);
}