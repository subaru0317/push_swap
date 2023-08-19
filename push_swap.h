/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smihata <smihata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:09:19 by smihata           #+#    #+#             */
/*   Updated: 2023/08/19 11:00:47 by smihata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

typedef int	t_elem;

typedef struct s_stack
{
	t_elem			*content;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// array_utils
void	print_int_array(int *arr, size_t arr_size);
int		is_sorted(int *arr, size_t arr_size);
void	ft_qsort(int *arr, int left, int right);

// coordinate_compression
int		*coordinate_compression(int *arr, size_t arr_size);

// error
void	ft_error(void);

// parse_args
// t_stack	*parse_args_to_stack(int argc, char **argv);

// push_swap
void	push_swap(int argc, char **argv);

// sort_four_to_six_elements_a
void	sort_four_to_six_elements_a(t_stack *a, t_stack *b);

// sort_four_to_six_elements_b
void	sort_four_to_six_elements_b(t_stack *a, t_stack *b);

// sort_seven_or_more_elements
void	sort_seven_or_more_elements(t_stack *a, t_stack *b);

// sort_three_elements
void	sort_three_elements_a(t_stack *a);
void	sort_three_elements_b(t_stack *b);

// sort_two_elements
void	sort_two_elements_a(t_stack *a);
void	sort_two_elements_b(t_stack *b);

// stack_basic_operations
void	push(t_stack *stack, int content);
void	pop(t_stack *stack);

// stack_debug_utils
// void	print_stack(t_stack *a, t_stack *b);

// stack_is_sorted
int		stack_is_sorted(t_stack *stack);

// stack_operation_double_reverse_rotate
void	execute_rrr(t_stack *a, t_stack *b);

// stack_operation_double_rotate
void	execute_rr(t_stack *a, t_stack *b);

// stack_operation_double_swap
void	execute_ss(t_stack *a, t_stack *b);

// stack_operation_push
void	pa(t_stack *a, t_stack *b);
void	execute_pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	execute_pb(t_stack *a, t_stack *b);

// stack_operation_reverse_rotate
void	rra(t_stack *a);
void	execute_rra(t_stack *a);
void	rrb(t_stack *b);
void	execute_rrb(t_stack *b);

// stack_operation_rotate
void	ra(t_stack *a);
void	execute_ra(t_stack *a);
void	rb(t_stack *b);
void	execute_rb(t_stack *b);

// stack_operation_swap
void	sa(t_stack *a);
void	execute_sa(t_stack *a);
void	sb(t_stack *b);
void	execute_sb(t_stack *b);

// stack_utils
int		stack_size(t_stack *stack);
void	stack_free(t_stack *stack);
t_elem	stack_min_content(t_stack *stack);
t_elem	stack_max_content(t_stack *stack);
int		stack_content_index(t_stack *stack, t_elem elem);

// stack_utils_two
t_stack	*stack_init(void);

// validate
int		is_int(char *nptr);
#endif