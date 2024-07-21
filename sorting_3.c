/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:01:57 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/21 22:54:55 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_b(t_stack **stack)
{
	t_stack	*lowest_value;

	lowest_value = find_lowest_value(stack);
	if (lowest_value == *stack)
		rb(stack);
	else if (lowest_value == (*stack)->next)
		rrb(stack);
	if ((*stack)->number < (*stack)->next->number)
		sb(stack);
}

void	sort_three_a(t_stack **stack)
{
	t_stack	*highest_value;

	highest_value = find_highest_value(stack);
	if (highest_value == *stack)
		ra(stack);
	else if (highest_value == (*stack)->next)
		rra(stack);
	if ((*stack)->number > (*stack)->next->number)
		sa(stack);
}

t_stack	*find_lowest_value(t_stack	**stack)
{
	t_stack	*value;
	t_stack	*lowestvalue;
	int		low;

	value = *stack;
	lowestvalue = *stack;
	low = (*stack)->number;
	while (value)
	{
		if (low > value->number)
			low = value->number;
		value = value->next;
	}
	while (lowestvalue)
	{
		if (low == lowestvalue->number)
			return (lowestvalue);
		lowestvalue = lowestvalue->next;
	}
	return (0);
}

t_stack	*find_highest_value(t_stack **stack)
{
	t_stack	*value;
	t_stack	*highestvalue;
	int		highest;

	value = *stack;
	highestvalue = *stack;
	highest = (*stack)->number;
	while (value)
	{
		if (highest < value->number)
			highest = value->number;
		value = value->next;
	}
	while (highestvalue)
	{
		if (highest == highestvalue->number)
			return (highestvalue);
		highestvalue = highestvalue->next;
	}
	return (0);
}
