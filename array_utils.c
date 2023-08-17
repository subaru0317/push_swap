/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:09:37 by smihata           #+#    #+#             */
/*   Updated: 2023/08/17 15:12:34 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_int_array(int *arr, size_t arr_size)
{
	size_t	i;

	if (!arr)
	{
		write(1, "arr is NULL.\n", 13);
		return ;
	}
	i = 0;
	while (i < arr_size)
	{
		ft_putnbr_fd(arr[i], 1);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_sorted(int *arr, size_t arr_size)
{
	size_t	i;

	i = 0;
	while (i + 1 < arr_size)
	{
		if (arr[i] >= arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_qsort(int *arr, int left, int right)
{
	int	pivot_index;
	int	pivot;
	int	i;
	int	j;

	if (right - left <= 1)
		return ;
	pivot_index = (left + right) / 2;
	pivot = arr[pivot_index];
	swap(&arr[pivot_index], &arr[right - 1]);
	i = left;
	j = left;
	while (j < right - 1)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap(&arr[i], &arr[right - 1]);
	ft_qsort(arr, left, i);
	ft_qsort(arr, i + 1, right);
}
