/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 04:05:57 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/23 19:38:40 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int      contains_dupplicate(const int *array, const int array_size);
int      *sort_array(int *array, const int array_size);

int arg_parsing(int argc, char *argv[])
{
    
    //need to redo this
    char **char_array;
    int *int_array;
    int i;
    int median;
    
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
            int_array[i - 1] = ft_atoi(argv[i]); //need to do a check for non numbers;
            i++;
        }
    }
    int_array = sort_array(int_array, argc - 1);
    if (contains_dupplicate(int_array, argc - 1))
    {
        printf("list contains dupplicate"); //TODO remove
        free (char_array);
        free (int_array);
        exit(EXIT_FAILURE);
    }
    printf("hi\n");
    median = int_array[(argc - 1) / 2];
    i = 0;
    // while (i < argc -1)
    // {
    //     printf("%i ", int_array[i]);
    //     i++;
    // } //kinda useless sorted check;
    // printf("done printing int array, median is %i\n", pushswap->median);
    free(int_array);
    free(char_array); //this actually doesnt free all need to put function
    return 0;
}

int contains_dupplicate(const int *array, const int array_size)
{
    int i;
    int limit;

    limit = array_size - 1;
    i = 0;
    while (i < limit)
    {
        if (array[i] == array[i + 1])
            return (1);
        i++;
    }
    return (0);
}

int *sort_array(int *array, const int array_size)
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
