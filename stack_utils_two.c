/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:30:03 by smihata           #+#    #+#             */
/*   Updated: 2023/08/19 12:30:12 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*acc;

	acc = (t_stack *)malloc(sizeof(t_stack));
	if (!acc)
		ft_error();
	acc->content = NULL;
	acc->next = acc;
	acc->prev = acc;
	return (acc);
}

void	push_array_to_stack(t_stack *stack, int *arr, int arr_size)
{
	int	i;

	i = arr_size - 1;
	while (i >= 0)
	{
		push(stack, arr[i]);
		i--;
	}
}
