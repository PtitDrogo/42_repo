/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:29:18 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/03 16:25:20 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
// # include "../libft/inc/libft.h"
// # include "../printf/inc/printf.h"

typedef struct s_node
{
	int             nbr;
    int             index;
    int             push_cost;
	bool            above_median;
    bool            cheapest;
    
    struct s_node	*target_node;
    struct s_node	*next;
    struct s_node	*prev;
}	t_node;

#endif