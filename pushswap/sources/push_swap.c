/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:24:46 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/03 16:33:20 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


typedef struct s_pushswap
{
    int                 number;
    struct s_pushswap   *next;
    struct s_pushswap   *previousnumber;
} t_pushswap;

t_pushswap    **init_number_list(int argc, char *argv[]);
t_pushswap    *ft_lstnew(void *content);
void    ft_lstadd_front(t_pushswap **list, t_pushswap *test);


int main(int argc, char *argv[])
{
    int i;

    i = 0;
    printf("hello\n");
    t_pushswap **pilea = init_number_list(argc, argv);
    while(pilea[i])
    {
        printf("number is %i\n", pilea[i]->number);
        i++;
    }
    return (0);
}

t_pushswap    **init_number_list(int argc, char *argv[])
{
    int i;

    i = 1;
    t_pushswap new_node;
    t_pushswap **pile_a;
    int         new_int;
    pile_a = malloc(sizeof(t_pushswap *) * argc);
    while (i < argc)
    {
        new_int = atoi(argv[i]);
        pile_a[i] = ft_lstnew(&new_int);
        ft_lstadd_front(pile_a, &new_node);
        i++;
    }
    return (pile_a);
}

t_pushswap    *ft_lstnew(void *content)
{
    t_pushswap    *node;
    
    // int newint = (int)*content;
    node = malloc(sizeof(t_pushswap));
    if (!node)
        return (NULL);
    node->number = *((int *)content);
    node->next = NULL;
    return (node);
}

void    ft_lstadd_front(t_pushswap **list, t_pushswap *test)
{
    if (*list == NULL)
        *list = test;
    else
    {
        test->next = *list;
        *list = test;
    }
}
// void    ft_lstadd_back(t_pushswap **list, t_pushswap *test)
// {
//     t_pushswap     *previous_last;

//     if (!test)
//         return ;
//     if (list)
//     {
//         if (!*list)
//             *list = test;
//         else
//         {
//             previous_last = ft_lstlast(*list);
//             previous_last->next = test;
//         }
//     }
// }