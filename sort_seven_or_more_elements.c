/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_seven_or_more_elements.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:09:01 by smihata           #+#    #+#             */
/*   Updated: 2023/08/17 15:07:36 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	choose_low_pivot(t_stack *stack)
// {
// 	int		min;
// 	int		max;
// 	t_stack	*sentinel;
// 	t_stack	*current_node;

// 	min = INT_MAX;			
// 	max = INT_MIN;
// 	sentinel = stack;
// 	current_node = stack->next;
// 	while (current_node != sentinel)
// 	{
// 		if (min > *(current_node->content))
// 			min = *(current_node->content);
// 		if (max < *(current_node->content))
// 			max = *(current_node->content);
// 		current_node = current_node->next;
// 	}
// 	return ((min + max) / 3);
// }

// static int	choose_high_pivot(t_stack *stack)
// {
// 	int		min;
// 	int		max;
// 	t_stack	*sentinel;
// 	t_stack	*current_node;

// 	min = INT_MAX;			
// 	max = INT_MIN;
// 	sentinel = stack;
// 	current_node = stack->next;
// 	while (current_node != sentinel)
// 	{
// 		if (min > *(current_node->content))
// 			min = *(current_node->content);
// 		if (max < *(current_node->content))
// 			max = *(current_node->content);
// 		current_node = current_node->next;
// 	}
// 	return (((min + max) * 2 + 2) / 3);
// }


static t_elem	choose_pivot(t_stack *stack)
{
	t_elem	min;
	t_elem	max;

	min = stack_min_content(stack);
	max = stack_max_content(stack);
	return (min / 2 + max / 2 + (min % 2 + max % 2 + 1) / 2);
}

#define EFFICIENT_SORT_THRESHOLD 6

void	short_stack_sort(t_stack *a, t_stack *b)
{
	int	b_size;

	b_size = stack_size(b);
	if (4 <= b_size && b_size <= 6)
	{
		sort_four_to_six_elements_b(a, b);
		return ;
	}
	if (b_size == 3)
		sort_three_elements_b(b);
	else if (b_size == 2)
		sort_two_elements_b(b);
	while (b_size--)
	{
		execute_pa(a, b);
		execute_ra(a);
	}
}

// void	recursive_quick_sort(t_stack *a, t_stack *b)
// {
// 	// 移植しても大丈夫？
// }


void stack_quick_sort(t_stack *a, t_stack *b)
{
	int	b_size;
	int	pivot_content;
	int	pa_count;

	b_size = stack_size(b);
	pa_count = 0;
	if (stack_is_sorted(b))
	{
		while (b_size--)
		{
			execute_pa(a, b);
			execute_ra(a);
		}
		return ;
	}
	else if (b_size <= EFFICIENT_SORT_THRESHOLD)
		short_stack_sort(a, b);
	else
	{
		pivot_content = choose_pivot(b);
		while (b_size--)
		{
			if (*(b->next->content) <= pivot_content)
				execute_rb(b);
			else
			{
				execute_pa(a, b);
				pa_count++;
			}
		}
		stack_quick_sort(a, b);
		while (pa_count--)
			execute_pb(a, b);
		stack_quick_sort(a, b);
	}
}

void	sort_seven_or_more_elements(t_stack *a, t_stack *b)
{
	int	pivot_content;
	int	a_size;
	int	b_size;
	int	remain_size;

	pivot_content = choose_pivot(a);
	a_size = stack_size(a);
	while (a_size--)
	{
		if (*(a->next->content) < pivot_content)
			execute_pb(a, b);
		else
			execute_ra(a);
	}
	a_size = stack_size(a);
	b_size = stack_size(b);
	stack_quick_sort(a, b);
	remain_size = stack_size(a) - b_size;
	while (remain_size--)
		execute_pb(a, b);
	stack_quick_sort(a, b);
}

