/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_debug_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:16:43 by smihata           #+#    #+#             */
/*   Updated: 2023/08/12 19:05:32 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	t_stack	*sentinel_a;
	t_stack	*sentinel_b;
	t_stack	*current_node_a;
	t_stack	*current_node_b;

	sentinel_a = a;
	current_node_a = a->next;
	sentinel_b = b;
	current_node_b = b->next;
	while (!(sentinel_a == current_node_a && sentinel_b == current_node_b))
	{
		if (sentinel_a != current_node_a)
		{
			ft_putnbr_fd(*(current_node_a->content), 1);
			current_node_a = current_node_a->next;
		}
		else
			write(1, "  ", 2);
		if (sentinel_b != current_node_b)
		{
			ft_putnbr_fd(*(current_node_a->content), 1);
	   		current_node_b = current_node_b->next;
    	}
    	else
			write(1, "  ", 2);
	write(1, "\n", 1);
  }
  write(1, "_ _\n", 4);
  write(1, "a b\n", 4);
}
