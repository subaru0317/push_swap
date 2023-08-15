/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:11:30 by smihata           #+#    #+#             */
/*   Updated: 2023/08/13 11:41:02 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

static int	binary_search(int *arr, int arr_size, int key)
{
	int	ng;
	int	ok;
	int	mid;

	ng = -1;
	ok = arr_size;
	while (ft_abs(ok - ng) > 1)
	{
		mid = (ok + ng) / 2;
		if (arr[mid] >= key)
			ok = mid;
		else
		ng = mid;
	}
	return (ok);
}

int	*coordinate_compression(int *arr, size_t arr_size)
{
	int		*compressed_arr;
	int		*sorted_arr;
	size_t	i;

	compressed_arr = (int *)malloc(sizeof(int) * arr_size);
	sorted_arr = (int *)malloc(sizeof(int) * arr_size);
	ft_memcpy(sorted_arr, arr, arr_size * sizeof(int));
	ft_qsort(sorted_arr, 0, arr_size);
	i = 0;
	while (i + 1 < arr_size)
	{
		if (sorted_arr[i] == sorted_arr[i + 1])
			return (NULL);
		i++;
	}
	i = 0;
	while (i < arr_size)
	{
		compressed_arr[i] = binary_search(sorted_arr, arr_size, arr[i]);
		i++;
	}
	free(sorted_arr);
	return (compressed_arr);
}
