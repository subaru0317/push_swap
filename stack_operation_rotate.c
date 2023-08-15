/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:15:53 by smihata           #+#    #+#             */
/*   Updated: 2023/08/12 18:49:18 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_stack	*preva;
	t_stack	*na;
	t_stack	*nna;

	if (stack_size(a) <= 1)
		return ;
	preva = a->prev;
	na = a->next;
	nna = a->next->next;
	a->next = nna;
	a->prev = na;
	na->next = a;
	na->prev = preva;
	nna->prev = a;
	preva->next = na;
}

void	execute_ra(t_stack *a)
{
	ra(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	ra(b);
}

void	execute_rb(t_stack *b)
{
	rb(b);
	write(1, "rb\n", 3);
}
