/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_to_six_elements_b.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:04:29 by smihata           #+#    #+#             */
/*   Updated: 2023/08/17 16:15:49 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top_b(t_stack *b)
{
	t_elem	min_content;
	int		min_content_index;
	int		b_size;
	int		index_from_bottom;

	min_content = stack_min_content(b);
	min_content_index = stack_content_index(b, min_content);
	b_size = stack_size(b);
	if (min_content_index <= b_size / 2)
	{
		while (min_content_index--)
			execute_rb(b);
	}
	else
	{
		index_from_bottom = b_size - min_content_index;
		while (index_from_bottom--)
			execute_rrb(b);
	}
}

void	sort_four_to_six_elements_b(t_stack *a, t_stack *b)
{
	int	count;
	int	i;
	int	b_size;

	count = stack_size(b) - 3;
	i = 0;
	while (i < count)
	{
		move_min_to_top_b(b);
		execute_pa(a, b);
		execute_ra(a);
		i++;
	}
	sort_three_elements_b(b);
	b_size = stack_size(b);
	while (b_size--)
	{
		execute_pa(a, b);
		execute_ra(a);
	}
}
