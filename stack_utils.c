/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:22:36 by smihata           #+#    #+#             */
/*   Updated: 2023/08/17 16:32:59 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	t_stack	*sentinel;
	int		siz;

	siz = 0;
	if (stack == NULL)
		return (siz);
	sentinel = stack;
	stack = stack->next;
	while (stack != sentinel)
	{
		siz++;
		stack = stack->next;
	}
	return (siz);
}

void	stack_free(t_stack *stack)
{
	int	siz;

	siz = stack_size(stack);
	while (siz >= 0)
	{
		pop(stack);
		siz--;
	}
	free(stack);
}

t_elem	stack_min_content(t_stack *stack)
{
	t_elem	min_content;
	t_stack	*current_node;
	t_stack	*sentinel;

	sentinel = stack;
	current_node = stack->next;
	min_content = INT_MAX;
	while (current_node != sentinel)
	{
		if (min_content > *(current_node->content))
			min_content = *(current_node->content);
		current_node = current_node->next;
	}
	return (min_content);
}

t_elem	stack_max_content(t_stack *stack)
{
	t_elem	max_content;
	t_stack	*current_node;
	t_stack	*sentinel;

	sentinel = stack;
	current_node = stack->next;
	max_content = INT_MIN;
	while (current_node != sentinel)
	{
		if (max_content < *(current_node->content))
			max_content = *(current_node->content);
		current_node = current_node->next;
	}
	return (max_content);
}

int	stack_content_index(t_stack *stack, t_elem elem)
{
	int		index;
	t_stack	*sentinel;
	t_stack	*current_node;

	sentinel = stack;
	current_node = stack->next;
	index = 0;
	while (current_node != sentinel)
	{
		if (elem == *(current_node->content))
			return (index);
		index++;
		current_node = current_node->next;
	}
	return (-1);
}
