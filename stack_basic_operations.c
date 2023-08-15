/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:53:53 by smihata           #+#    #+#             */
/*   Updated: 2023/08/15 11:00:53 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*stack_create_node(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = (t_elem *)malloc(sizeof(t_elem));
	if (!new_node->content)
	{
		free(new_node);
		return (NULL);
	}
	*(new_node->content) = content;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	push(t_stack *stack, int content)
{
	t_stack	*new_node;
	t_stack	*nstack;

	new_node = stack_create_node(content);
	nstack = stack->next;
	stack->next = new_node;
	new_node->prev = stack;
	new_node->next = nstack;
	nstack->prev = new_node;
}

void	pop(t_stack *stack)
{
	t_stack	*nstack;
	t_stack	*nnstack;

	if (stack->next == stack)
		return ;
	nstack = stack->next;
	nnstack = stack->next->next;
	stack->next = nnstack;
	nnstack->prev = stack;
	free(nstack->content);
	free(nstack);
}
