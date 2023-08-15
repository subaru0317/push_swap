/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_double_rotate.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:30:34 by smihata           #+#    #+#             */
/*   Updated: 2023/08/12 18:35:20 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	execute_rr(t_stack *a, t_stack *b)
{
	rr(a, b);
	write(1, "rr\n", 3);
}
