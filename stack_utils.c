/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:22:36 by smihata           #+#    #+#             */
/*   Updated: 2023/08/17 14:05:48 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*acc;

	acc = (t_stack *)malloc(sizeof(t_stack));
	if (!acc)
		return (NULL);
	acc->content = NULL;
	acc->next = acc;
	acc->prev = acc;
	return (acc);
}

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
	int siz;
	
	siz = stack_size(stack);
	while (siz >= 0)
	{
		pop(stack);
		siz--;
	}
	free(stack); // sentinel
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