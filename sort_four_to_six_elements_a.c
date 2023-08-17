/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_to_six_elements_a.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:02:49 by smihata           #+#    #+#             */
/*   Updated: 2023/08/17 16:11:58 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top_a(t_stack *a)
{
	t_elem	min_content;
	int		min_content_index;
	int		a_size;
	int		index_from_bottom;

	min_content = stack_min_content(a);
	min_content_index = stack_content_index(a, min_content);
	a_size = stack_size(a);
	if (min_content_index <= a_size / 2)
	{
		while (min_content_index--)
			execute_ra(a);
	}
	else
	{
		index_from_bottom = a_size - min_content_index;
		while (index_from_bottom--)
			execute_rra(a);
	}
}

void	sort_four_to_six_elements_a(t_stack *a, t_stack *b)
{
	int	count;
	int	i;

	count = stack_size(a) - 3;
	i = 0;
	while (i < count)
	{
		move_min_to_top_a(a);
		execute_pb(a, b);
		i++;
	}
	sort_three_elements_a(a);
	i = 0;
	while (i < count)
	{
		execute_pa(a, b);
		i++;
	}
}
