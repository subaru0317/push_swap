/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:15:35 by smihata           #+#    #+#             */
/*   Updated: 2023/08/12 18:49:05 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	push(a, *(b->next->content));
	pop(b);
}

void	execute_pa(t_stack *a, t_stack *b)
{
	pa(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	pa(b, a);
}

void	execute_pb(t_stack *a, t_stack *b)
{
	pb(a, b);
	write(1, "pb\n", 3);
}
