/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 04:05:57 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/14 17:33:25 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int arg_parsing(int argc, char *argv[], t_list  *pushswap)
{
    
    //need to redo this
    char **char_array;
    int *int_array;
    int i;
    
    char_array = NULL;
    int_array = NULL;
    i = 1;
    if (argc == 1)
		exit(EXIT_FAILURE);
    else if (argc == 2)
        char_array = ft_split(argv[1], ' '); //need to atoi this later;
    else if (argc > 2)
    {
        int_array = malloc(sizeof(int) * argc - 1);
        while (i < argc)
        {
            int_array[i - 1] = atoi(argv[i]);
            i++;
        }
    }
    int_array = sort_array(int_array, argc - 1);
    pushswap->median = int_array[(argc - 1) / 2];
    i = 0;
    while (i < argc -1)
    {
        printf("%i ", int_array[i]);
        i++;
    }
    printf("done printing int array, median is %i\n", pushswap->median);
    free(int_array);
    return 0;
}

int *sort_array(int *array, int array_size)
{
    int i;
    int j;
    
    i = 0;
    while (i < array_size)
    {
        j = i;
        while (j < array_size)
        {
            if (array[i] > array[j])
                swap_int(&array[i], &array[j]);
            j++;
        }
        i++;
    }
    return (array);
}
