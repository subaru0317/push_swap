// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   parse_args.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/08/17 18:28:13 by smihata           #+#    #+#             */
// /*   Updated: 2023/08/19 11:00:23 by smihata          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// static int	*string_array_to_int_array(char **str)
// {
// 	int		len;
// 	int		i;
// 	int		*result;

// 	len = 0;
// 	while (str && str[len])
// 		len++;
// 	result = (int *)malloc(sizeof(int) * len);
// 	if (!result)
// 		ft_error();
// 	i = 0;
// 	while (i < len)
// 	{
// 		if (!is_int(str[i]))
// 			ft_error();
// 		result[i] = atoi(str[i]);
// 		i++;
// 	}	
// 	return (result);
// }

// // char	**ft_strdup_array(int argc, char **argv)
// // {
// // 	int		arr_size;
// // 	char	**str;
// // 	int		i;

// // 	arr_size = argc - 1;
// // 	str = (char **)malloc(sizeof(char *) * (arr_size + 1));
// // 	if (!str)
// // 		ft_error();
// // 	i = 0;
// // 	while (i + 1 < argc)
// // 	{
// // 		str[i] = ft_strdup(argv[i + 1]);
// // 		if (!str[i])
// // 			ft_error();
// // 		i++;
// // 	}
// // 	str[arr_size] = NULL;
// // 	return (str);
// // }

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
	// char	**str;
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

// void	push_array_to_stack(t_stack *stack, int *arr, int arr_size)
// {
// 	int	i;

// 	i = arr_size - 1;
// 	while (i >= 0)
// 	{
// 		push(stack, arr[i]);
// 		i--;
// 	}
// }

// t_stack	*parse_args_to_stack(int argc, char **argv)
// {
// 	int		*arr;
// 	int		*compressed_arr;
// 	int		i;
// 	t_stack	*stack;
// 	char	**str;
// 	size_t	arr_size;

// 	str = argv_to_string_array(argc, argv);
// 	arr_size = 0;
// 	while (str != NULL && str[arr_size])
// 		arr_size++;
// 	arr = string_array_to_int_array(str);
// 	free(str);
// 	if (is_sorted(arr, arr_size))
// 		exit(0);
// 	compressed_arr = coordinate_compression(arr, arr_size);
// 	stack = stack_init();
// 	push_array_to_stack(stack, compressed_arr, arr_size);
// 	free(compressed_arr);
// 	free(arr);
// 	i = 0;
// 	while ((size_t)i < arr_size)
// 	{
// 		free(str[i]);
// 		i++;
// 	}
// 	return (stack);
// }
