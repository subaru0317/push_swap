/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:12:25 by smihata           #+#    #+#             */
/*   Updated: 2023/08/12 18:49:23 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_stack	*na;
	t_stack	*nna;
	t_stack	*nnna;

	na = a->next;
	nna = a->next->next;
	nnna = a->next->next->next;
	a->next = nna;
	na->next = nnna;
	na->prev = nna;
	nna->next = na;
	nna->prev = a;
	nnna->prev = na;
}

void	execute_sa(t_stack *a)
{
	sa(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	sa(b);
}

void	execute_sb(t_stack *b)
{
	sb(b);
	write(1, "sb\n", 3);
}
