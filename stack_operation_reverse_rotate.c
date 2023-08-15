/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_reverse_rotate.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:27:05 by smihata           #+#    #+#             */
/*   Updated: 2023/08/12 18:49:12 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	t_stack	*preva;
	t_stack	*ppreva;
	t_stack	*na;

	preva = a->prev;
	ppreva = a->prev->prev;
	na = a->next;
	a->next = preva;
	a->prev = ppreva;
	na->prev = preva;
	preva->next = na;
	preva->prev = a;
	ppreva->next = a;
}

void	execute_rra(t_stack *a)
{
	rra(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	rra(b);
}

void	execute_rrb(t_stack *b)
{
	rrb(b);
	write(1, "rrb\n", 4);
}
