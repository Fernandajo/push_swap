/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:43:47 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/23 19:00:53 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"
# include "Libft/libft.h"
# include <stdlib.h>
# include <limits.h>

//ERROR DEFINES
# define ERR_INV "Error: Invalid characters\n"
# define ERR_DUP "Error: Duplicated numbers\n"
# define ERR_MAX "Error: number exceeds int limits\n"

typedef struct s_stack 
{
	long			number;
	int				index;
	int				cost;
	int				sumop;
	struct s_stack	*neigh;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	print_stack(t_stack *stack, char c);
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	print_stack_cost(t_stack *stack, char c);
void	print_stack_neigh(t_stack *stack, char c);

//creating_stack
t_stack	*creating_stack(char **args, int i);
t_stack	*createnode(long nbr);
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast_ps(t_stack *lst);
void	update_index(t_stack *stack);

//creating_stacks_helper
long	ft_atoi_ps(const char *str, t_stack	*stack);
int		checkdup(t_stack *stack);
int		count_nodes(t_stack *stack);
t_stack	*create_b(t_stack **stack_a, int j);

// free_e_exit
void	exit_error(t_stack *stack, char *msg);
void	free_stack(t_stack *stack_a);
int		count_lines_matrix(char **matrix);
void	free_matrix(char **matrix);

//operations
void	swap(t_stack **stack);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack	**stack);
void	revrotate(t_stack **stack);
void	rra(t_stack **stack_a);

//operations 2
void	sa(t_stack	**stack_a);
void	sb(t_stack	**stack_b);
void	ss(t_stack	**stack_a, t_stack	**stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

//operations3
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//sorting
int		sum_op(t_stack *stack_a);
t_stack	*lowest_opnum(t_stack *stack);
void	sorting_5(t_stack **stack_a, t_stack **stack_b);
int		media(t_stack **stack);

//sorting_3
void	sort_three_b(t_stack **stack);
void	sort_three_a(t_stack **stack);
t_stack	*find_lowest_value(t_stack	**stack);
t_stack	*find_highest_value(t_stack **stack);

//utils
void	ft_lstadd_front_ps(t_stack **lst, t_stack *new);
void	find_cost(t_stack **stack);
void	find_neighbour(t_stack **stack_a, t_stack **stack_b);
int		difference(int a, int b);
int		lowest_value(t_stack *stack_a, t_stack *stack_b);

//execution
void	exec(t_stack **stack_a, t_stack **stack_b);
void	positiv(t_stack **stack_a, t_stack **stack_b, t_stack *temp);
void	negativ(t_stack **stack_a, t_stack **stack_b, t_stack *temp);
void	diferente(t_stack **stack_a, t_stack **stack_b, t_stack *temp);
void	find_top(t_stack **stack_b);

#endif