/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_to_six_elements_a.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 18:02:49 by smihata           #+#    #+#             */
/*   Updated: 2023/08/17 12:08:54 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top_a(t_stack *a)
{
	int		min_content;
	int		min_content_index;
	int		a_size;
	int		current_node_index;
	t_stack	*current_node;
	t_stack	*sentinel;

	sentinel = a;
	current_node = a->next;
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
	a_size = stack_size(a);
	current_node = a->next;
	if (min_content_index <= a_size / 2)
	{
		int index = 0;
		while (index < min_content_index)
		{
			execute_ra(a);
			index++;
		}
	}
	else
	{
		int index = 0;
		int index_from_bottom = a_size - min_content_index;
		while (index < index_from_bottom)
		{
			execute_rra(a);
			index++;
		}
	}
}


void	sort_four_to_six_elements_a(t_stack *a, t_stack *b)
{
	int count;
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