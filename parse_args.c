/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:15:18 by smihata           #+#    #+#             */
/*   Updated: 2023/08/19 12:34:25 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*string_array_to_int_array(char **str)
{
	int		len;
	int		i;
	int		*result;

	len = 0;
	while (str && str[len])
		len++;
	result = (int *)malloc(sizeof(int) * len);
	if (!result)
		ft_error();
	i = 0;
	while (i < len)
	{
		if (!is_int(str[i]))
			ft_error();
		result[i] = atoi(str[i]);
		i++;
	}
	return (result);
}

static char	**ft_strdup_array(int argc, char **argv)
{
	int		arr_size;
	char	**str;
	int		i;

	arr_size = argc - 1;
	str = (char **)malloc(sizeof(char *) * (arr_size + 1));
	if (!str)
		ft_error();
	i = 0;
	while (i + 1 < argc)
	{
		str[i] = ft_strdup(argv[i + 1]);
		if (!str[i])
			ft_error();
		i++;
	}
	str[arr_size] = NULL;
	return (str);
}

static char	**argv_to_string_array(int argc, char **argv)
{
	char	**str;

	if (argc <= 1)
		exit(0);
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (!str)
			ft_error();
	}
	else
		str = ft_strdup_array(argc, argv);
	return (str);
}

void	string_array_free(char **strings)
{
	size_t	i;
	size_t	total_strings;

	total_strings = count_strings(strings);
	i = 0;
	while ((size_t)i < total_strings)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

t_stack	*parse_args_to_stack(int argc, char **argv)
{
	int		*arr;
	int		*compressed_arr;
	t_stack	*stack;
	char	**str;
	size_t	arr_size;

	str = argv_to_string_array(argc, argv);
	arr_size = count_strings(str);
	arr = string_array_to_int_array(str);
	string_array_free(str);
	if (is_sorted(arr, arr_size))
		exit(0);
	compressed_arr = coordinate_compression(arr, arr_size);
	free(arr);
	stack = stack_init();
	push_array_to_stack(stack, compressed_arr, arr_size);
	free(compressed_arr);
	return (stack);
}
