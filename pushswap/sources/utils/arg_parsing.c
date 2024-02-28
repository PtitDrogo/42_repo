/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfreydie <tfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 04:05:57 by tfreydie          #+#    #+#             */
/*   Updated: 2024/02/28 20:47:16 by tfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		contains_dupplicate(const int *array, const int array_size);
static int		*sort_array(int *array, const int array_size);
static int		*process_two_args_case(int argc, char *argv[], int *size);
static int		*process_numbers_arg(int argc, char *argv[], int *size);

int	arg_parsing(int argc, char *argv[], int *medianpointer, t_node **roota)
{
	int		*int_array;
	int		size;

	int_array = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		int_array = process_two_args_case(argc, argv, &size);
		if (int_array == NULL)
			return (0);
	}
	else if (argc > 2)
	{
		int_array = process_numbers_arg(argc, argv, &size);
		if (int_array == NULL)
			return (0);
	}
	if (init_number_list(size, int_array, roota) == 0)
		return (free (int_array), 0);
	int_array = sort_array(int_array, size);
	*medianpointer = int_array[size / 2];
	if (contains_dupplicate(int_array, size))
		return (free (int_array), 0);
	return (free (int_array), 1);
}

static int	contains_dupplicate(const int *array, const int array_size)
{
	int	i;
	int	limit;

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

static int	*sort_array(int *array, const int array_size)
{
	int	i;
	int	j;

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

static int	*process_numbers_arg(int argc, char *argv[], int *size)
{
	int		i;
	int		*int_array;
	long	temp;

	i = 1;
	int_array = malloc(sizeof(int) * (argc - 1));
	if (!int_array)
		return (NULL);
	while (i < argc)
	{
		temp = ft_safe_atoi(argv[i]);
		if (temp == ATOI_ERROR)
			return (free(int_array), NULL);
		int_array[i - 1] = temp;
		i++;
	}
	*size = argc - 1;
	return (int_array);
}

static int	*process_two_args_case(int argc, char *argv[], int *size)
{
	int		i;
	int		j;
	long	temp;
	char	**char_array;
	int		*int_array;

	char_array = ft_split(argv[1], ' ');
	if (!char_array)
		return (0);
	i = 0;
	while (char_array[i])
		i++;
	int_array = malloc(sizeof(int) * i);
	if (!int_array)
		return (free_array((void **)char_array), NULL);
	j = -1;
	while (++j < i)
	{
		temp = ft_safe_atoi(char_array[j]);
		if (temp == ATOI_ERROR)
			return (free_array((void **)char_array), free (int_array), NULL);
		int_array[j] = (int)temp;
	}
	*size = i;
	return (free_array((void **)char_array), int_array);
}
