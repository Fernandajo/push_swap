/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:43:50 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/23 18:31:44 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = NULL;
	args = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		stack_a = creating_stack(args, 0);
	}
	else
		stack_a = creating_stack(argv, 1);
	if (count_nodes(stack_a) == 2)
	{
		if (stack_a->number > stack_a->next->number)
			sa(&stack_a);
	}
	else
		push_swap(&stack_a, &stack_b);
	free_stack(stack_a);
	return (0);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (count_nodes(*stack_a) > 6)
	{
		*stack_b = create_b(stack_a, 3);
		sort_three_b(stack_b);
		while (count_nodes(*stack_a) > 0)
		{
			find_cost(stack_a);
			find_cost(stack_b);
			find_neighbour(stack_a, stack_b);
			exec(stack_a, stack_b);
		}
		find_top(stack_b);
		while (count_nodes(*stack_b) > 0)
			pa(stack_a, stack_b);
	}
	else
	{
		if (count_nodes(*stack_a) == 3)
		{
			(void)stack_b;
			sort_three_a(stack_a);
		}
		else if (count_nodes(*stack_a) > 1)
			sorting_5(stack_a, stack_b);
	}
}
