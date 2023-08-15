/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation_double_swap.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:24:06 by smihata           #+#    #+#             */
/*   Updated: 2023/08/12 18:35:14 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	execute_ss(t_stack *a, t_stack *b)
{
	ss(a, b);
	write(1, "ss\n", 3);
}
