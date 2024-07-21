/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:31:49 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/23 16:00:25 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sum_op(t_stack *stack_a)
{
	int	ret;

	if (stack_a->cost >= 0 && stack_a->neigh->cost >= 0)
	{
		if (stack_a->cost > stack_a->neigh->cost)
			ret = stack_a->cost;
		else
			ret = stack_a->neigh->cost;
	}
	else if (stack_a->cost < 0 && stack_a->neigh->cost < 0)
	{
		if (stack_a->cost > stack_a->neigh->cost)
			ret = stack_a->neigh->cost * -1;
		else
			ret = stack_a->cost * -1;
	}
	else
	{
		ret = (stack_a->cost + (stack_a->neigh->cost * -1));
		if (ret < 0)
			ret *= -1;
	}
	return (ret);
}

t_stack	*lowest_opnum(t_stack *stack)
{
	t_stack	*ret;

	ret = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->sumop < ret->sumop)
			ret = stack;
		stack = stack->next;
	}
	return (ret);
}

void	sorting_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*low;

	*stack_b = NULL;
	while (count_nodes(*stack_a) > 3)
	{
		find_cost(stack_a);
		low = find_lowest_value(stack_a);
		if (low->cost >= 0)
		{
			while (low->cost-- > 0)
				ra(stack_a);
		}
		else
		{
			while (low->cost++ < 0)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three_a(stack_a);
	while ((*stack_b) != NULL)
		pa(stack_a, stack_b);
}

int	media(t_stack **stack)
{
	int	total;
	int	medium;

	total = count_nodes(*stack);
	medium = total / 2;
	return (medium);
}
