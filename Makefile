# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 14:43:41 by fjoestin          #+#    #+#              #
#    Updated: 2024/04/28 16:14:58 by fjoestin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   push_swap

CC      =   cc
CFLAGS  =   -Wall -Werror -Wextra -g 

LIBS    =    ./Libft/libft.a

PRINTF  =    ./ft_printf/libftprintf.a

SRCS	=	push_swap.c \
			creating_stacks.c \
			free_e_exit.c \
			creating_stacks_helper.c \
			operations.c \
			utils.c \
			operations2.c \
			operations3.c \
			sorting_3.c \
			sorting.c \
			execution.c

OBJS	=	$(addprefix output/,$(SRCS:.c=.o))

all:		$(NAME)
$(NAME): $(OBJS)
			make -C ./Libft
			make -C ./ft_printf
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(PRINTF) -o $(NAME)

output/%.o: %.c | output
		$(CC) $(CFLAGS) -c $< -o $@
	
output:
		mkdir -p output
	
clean:
			make clean -C ./Libft
			make clean -C ./ft_printf
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME) $(LIBS) $(PRINTF)
			
re:			fclean all

norminette: 
	norminette $(SRCS)
.PHONY: all clean fclean re
