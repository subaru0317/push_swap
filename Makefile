NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	array_utils.c \
			coordinate_compression.c \
			error.c \
			parse_args.c \
			push_swap.c \
			sort_four_to_six_elements_a.c \
			sort_four_to_six_elements_b.c \
			sort_seven_or_more_elements.c \
			sort_three_elements.c \
			sort_two_elements.c \
			stack_basic_operations.c \
			stack_debug_utils.c \
			stack_is_sorted.c \
			stack_operation_double_reverse_rotate.c \
			stack_operation_double_rotate.c \
			stack_operation_double_swap.c \
			stack_operation_push.c \
			stack_operation_reverse_rotate.c \
			stack_operation_rotate.c \
			stack_operation_swap.c \
			stack_utils.c \
			stack_utils_two.c \
			validate.c
OBJS	=	${SRCS:%.c=%.o}

%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} libft/libft.a -o $@

all: ${NAME}

clean:
	${MAKE} -C ./libft clean
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
