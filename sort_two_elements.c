/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:24:36 by smihata           #+#    #+#             */
/*   Updated: 2023/08/10 17:24:45 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elements_a(t_stack *a)
{
	if (*(a->next->content) > *(a->next->next->content))
		execute_sa(a);
}

void	sort_two_elements_b(t_stack *b)
{
	if (*(b->next->content) > *(b->next->next->content))
		execute_sb(b);
}
