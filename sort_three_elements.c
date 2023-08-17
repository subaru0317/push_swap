/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:25:41 by smihata           #+#    #+#             */
/*   Updated: 2023/08/17 16:24:58 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements_a(t_stack *a)
{
	t_elem	first;
	t_elem	second;
	t_elem	third;

	first = *(a->next->content);
	second = *(a->next->next->content);
	third = *(a->next->next->next->content);
	if (first < second && second > third && first < third)
	{
		execute_sa(a);
		execute_ra(a);
	}
	else if (first > second && second < third && first < third)
		execute_sa(a);
	else if (first < second && second > first && first > third)
		execute_rra(a);
	else if (first > second && second < third && first > third)
		execute_ra(a);
	else if (first > second && second > third && first > third)
	{
		execute_sa(a);
		execute_rra(a);
	}
}

void	sort_three_elements_b(t_stack *b)
{
	t_elem	first;
	t_elem	second;
	t_elem	third;

	first = *(b->next->content);
	second = *(b->next->next->content);
	third = *(b->next->next->next->content);
	if (first < second && second > third && first < third)
	{
		execute_sb(b);
		execute_rb(b);
	}
	else if (first > second && second < third && first < third)
		execute_sb(b);
	else if (first < second && second > first && first > third)
		execute_rrb(b);
	else if (first > second && second < third && first > third)
		execute_rb(b);
	else if (first > second && second > third && first > third)
	{
		execute_sb(b);
		execute_rrb(b);
	}
}
