SRCS = push_swap.c push_swap_utils.c rules_1.c

NAME = push_swap

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

ARRC = ar rcs



${NAME}:	${SRCS}
				make all -C ./libft
				${GCC} ${CFLAGS} ${SRCS} libft/libft.a -o ${NAME}



all:	${NAME}


clean:
				make clean -C ./libft

fclean:	clean
				rm -f ${NAME}
				make fclean -C ./libft

re: fclean all

.PHONY : all clean fclean re
