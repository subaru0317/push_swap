/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:22:36 by smihata           #+#    #+#             */
/*   Updated: 2023/08/15 11:15:35 by smihata          ###   ########.fr       */
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