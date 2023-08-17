/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:33:07 by smihata           #+#    #+#             */
/*   Updated: 2023/08/17 16:30:05 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	t_stack	*sentinel;
	t_stack	*current_node;
	t_stack	*next_node;

	sentinel = stack;
	current_node = stack->next;
	next_node = current_node->next;
	while (next_node != sentinel)
	{
		if (*(current_node->content) > *(next_node->content))
			return (0);
		current_node = next_node;
		next_node = next_node->next;
	}
	return (1);
}
