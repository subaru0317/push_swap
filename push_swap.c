/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:10:34 by smihata           #+#    #+#             */
/*   Updated: 2023/08/19 12:35:01 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	a = parse_args_to_stack(argc, argv);
	b = stack_init();
	len = stack_size(a);
	if (len <= 1)
		return ;
	else if (len == 2)
		sort_two_elements_a(a);
	else if (len == 3)
		sort_three_elements_a(a);
	else if (4 <= len && len <= 6)
		sort_four_to_six_elements_a(a, b);
	else
		sort_seven_or_more_elements(a, b);
	stack_free(a);
	stack_free(b);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
}

// __attribute__((destructor)) static void	destructor()
// {
//     system("leaks -q push_swap");
// }
