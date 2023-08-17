/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_to_six_elements_b.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:04:29 by smihata           #+#    #+#             */
/*   Updated: 2023/08/17 12:29:41 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top_b(t_stack *b)
{
	int		min_content;
	int		min_content_index;
	int		b_size;
	int		current_node_index;
	t_stack	*current_node;
	t_stack	*sentinel;

	sentinel = b;
	current_node = b->next;
	min_content = INT_MAX;
	min_content_index = 0;
	current_node_index = 0;
	while (current_node != sentinel)
	{
		if (min_content > *(current_node->content))
		{
			min_content = *(current_node->content);
			min_content_index = current_node_index;
		}
		current_node = current_node->next;
		current_node_index++;
	}
	b_size = stack_size(b);
	current_node = b->next;
	if (min_content_index <= b_size / 2)
	{
		int index = 0;
		while (index < min_content_index)
		{
			execute_rb(b);
			index++;
		}
	}
	else
	{
		int index = 0;
		int index_from_bottom = b_size - min_content_index;
		while (index < index_from_bottom)
		{
			execute_rrb(b);
			index++;
		}
	}
}


void	sort_four_to_six_elements_b(t_stack *a, t_stack *b)
{
	int count;
	int	i;
	int b_size;

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