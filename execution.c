/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 03:29:27 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/23 14:17:50 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	temp = lowest_opnum(*stack_a);
	if (temp->cost >= 0 && temp->neigh->cost >= 0)
		positiv(stack_a, stack_b, temp);
	if (temp->cost < 0 && temp->neigh->cost < 0)
		negativ(stack_a, stack_b, temp);
	if ((temp->cost >= 0 && temp->neigh->cost < 0)
		|| (temp->cost < 0 && temp->neigh->cost >= 0))
		diferente(stack_a, stack_b, temp);
	pb(stack_a, stack_b);
	if ((*stack_b)->number < (*stack_b)->next->number)
		sb(stack_b);
}

void	positiv(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost > 0 && temp->neigh->cost > 0)
	{
		rr(stack_a, stack_b);
		temp->cost--;
		temp->neigh->cost--;
	}
	while (temp->cost > 0)
	{
		ra(stack_a);
		temp->cost--;
	}
	while (temp->neigh->cost > 0)
	{
		rb(stack_b);
		temp->neigh->cost--;
	}
}

void	negativ(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost < 0 && temp->neigh->cost < 0)
	{
		rrr(stack_a, stack_b);
		temp->cost++;
		temp->neigh->cost++;
	}
	while (temp->cost < 0)
	{
		rra(stack_a);
		temp->cost++;
	}
	while (temp->neigh->cost < 0)
	{
		rrb(stack_b);
		temp->neigh->cost++;
	}
}

void	diferente(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost > 0)
	{
		ra(stack_a);
		temp->cost--;
	}
	while (temp->neigh->cost > 0)
	{
		rb(stack_b);
		temp->neigh->cost--;
	}
	while (temp->cost < 0)
	{
		rra(stack_a);
		temp->cost++;
	}
	while (temp->neigh->cost < 0)
	{
		rrb(stack_b);
		temp->neigh->cost++;
	}
}

void	find_top(t_stack **stack_b)
{
	t_stack	*highest;
	int		medium;

	highest = find_highest_value(stack_b);
	medium = media(stack_b);
	if (highest->index > medium)
	{
		while (highest->index != 0)
			rrb(stack_b);
	}
	else if (highest->index <= medium)
	{
		while (highest->index != 0)
			rb(stack_b);
	}
}
