/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:10:34 by smihata           #+#    #+#             */
/*   Updated: 2023/08/19 11:17:08 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *string_array_to_int_array(char **str)
{
	int		len;
	int		i;
	int		*result;

	len = 0;
	while (str && str[len])
		len++;
	result = (int *)malloc(sizeof(int) * len);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (!is_int(str[i]))
			return (NULL);
		result[i] = atoi(str[i]);
		i++;
	}	
	return (result);
}

char	**argv_to_string_array(int argc, char **argv)
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
	{
		int		arr_size;
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
	}
	return (str);
}

// 途中でError発生した時用にfreeすること
static t_stack	*parse_args_to_stack(int argc, char **argv)
{
	int		*arr;
	int		*compressed_arr;
	int		i;
	t_stack	*stack;
	char	**str;
	size_t	arr_size;

	// stack = stack_init();
	// if (argc <= 1)
	// 	return (NULL);
	// if (argc == 2)
	// {
	// 	str = ft_split(argv[1], ' ');
	// 	if (!str)
	// 		ft_error();
	// 	arr_size = 0;
	// 	while (str != NULL && str[arr_size])
	// 		arr_size++;
	// }
	// else
	// {
	// 	i = 0;
	// 	arr_size = argc - 1;
	// 	str = (char **)malloc(sizeof(char *) * (arr_size + 1));
	// 	if (!str)
	// 		ft_error();
	// 	while (i + 1 < argc)
	// 	{
	// 		str[i] = ft_strdup(argv[i + 1]);
	// 		i++;
	// 	}
	// 	str[arr_size] = NULL;
	// }

	str = argv_to_string_array(argc, argv);
	arr_size = 0;
	while (str != NULL && str[arr_size])
		arr_size++;
	arr = string_array_to_int_array(str);
	if (!arr)
		ft_error();
	i = 0;
	while ((size_t)i < arr_size)
	{
		free(str[i]);
		i++;
	}
	free(str);
	if (!arr)
		ft_error();
	if (is_sorted(arr, arr_size))
    	return (NULL);
	compressed_arr = coordinate_compression(arr, arr_size);
	free(arr);
	if (!compressed_arr)
		ft_error();
	i = arr_size - 1;
	stack = stack_init();
	while (i >= 0)
	{
		push(stack, compressed_arr[i]);
    	i--;
	}
	free(compressed_arr);
	return (stack);
}

void	push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	a = parse_args_to_stack(argc, argv);
	b = stack_init();
	len = stack_size(a);
	if (len <= 1)
		return ;
 	else if (len == 2)
    	sort_two_elements_a(a);
  	else if (len == 3)
		sort_three_elements_a(a);
  	else if (4 <= len && len <= 6)
		sort_four_to_six_elements_a(a, b);
  	else
    	sort_seven_or_more_elements(a, b);
	stack_free(a);
	stack_free(b);
}

int main(int argc, char **argv)
{
	push_swap(argc, argv);
}