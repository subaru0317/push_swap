/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_double_reverse_rotate.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:29:21 by smihata           #+#    #+#             */
/*   Updated: 2023/08/12 18:35:26 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

void	execute_rrr(t_stack *a, t_stack *b)
{
	rrr(a, b);
	write(1, "rrr\n", 4);
}
