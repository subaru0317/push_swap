/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:25:41 by smihata           #+#    #+#             */
/*   Updated: 2023/08/10 17:26:44 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements_a(t_stack *a)
{
	int	first;
	int	second;
	int	third;
	first = *(a->next->content);
	second = *(a->next->next->content);
	third = *(a->next->next->next->content);
	if (first < second && second < third && first < third)
	{
		// none
	}
	// 1 3 2
	else if (first < second && second > third && first < third)
	{
		execute_sa(a);
		execute_ra(a);
	}
	// 2 1 3
	else if (first > second && second < third && first < third)
		execute_sa(a);
	// 2 3 1
	else if (first < second && second > first && first > third)
		execute_rra(a);
	// 3 1 2
	else if (first > second && second < third && first > third)
		execute_ra(a);
	// 3 2 1
	else if (first > second && second > third && first > third)
	{
		execute_sa(a);
		execute_rra(a);
	}
}

void	sort_three_elements_b(t_stack *b)
{
	int	first;
	int	second;
	int	third;
	first = *(b->next->content);
	second = *(b->next->next->content);
	third = *(b->next->next->next->content);
	// 1 2 3
	if (first < second && second < third && first < third)
	{
		// none
	}
	// 1 3 2
	else if (first < second && second > third && first < third)
	{
		execute_sb(b);
		execute_rb(b);
	}
	// 2 1 3
	else if (first > second && second < third && first < third)
		execute_sb(b);
	// 2 3 1
	else if (first < second && second > first && first > third)
		execute_rrb(b);
	// 3 1 2
	else if (first > second && second < third && first > third)
		execute_rb(b);
	// 3 2 1
	else if (first > second && second > third && first > third)
	{
		execute_sb(b);
		execute_rrb(b);
	}
}