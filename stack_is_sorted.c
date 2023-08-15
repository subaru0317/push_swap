/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:33:07 by smihata           #+#    #+#             */
/*   Updated: 2023/08/12 19:00:13 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_is_sorted(t_stack *arr)
{
  t_stack *sentinel;
  t_stack *current_node;
  t_stack *next_node;

  sentinel = arr;
  current_node = arr->next;
  next_node = current_node->next;
  while (next_node != sentinel)
  {
    if (*(current_node->content) > *(next_node->content))
      return (0);
    current_node = next_node;
    next_node = next_node->next;
  }
  return (1);
}