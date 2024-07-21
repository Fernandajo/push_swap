/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:46:00 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/23 15:45:12 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	if (*stack == NULL)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*node;

	if (from == NULL)
		return ;
	node = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	node->prev = NULL;
	if (*to == NULL)
	{
		*to = node;
		node->next = NULL;
	}
	else
	{
		node->next = *to;
		node->next->prev = node;
		*to = node;
	}
}

void	rotate(t_stack	**stack)
{
	t_stack	*node;

	node = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	ft_lstadd_back_ps(stack, node);
}

void	revrotate(t_stack **stack)
{
	t_stack	*node;

	while ((*stack)->next->next)
	{
		*stack = (*stack)->next;
	}
	node = (*stack)->next;
	(*stack)->next = NULL;
	while ((*stack)->prev)
		*stack = (*stack)->prev;
	(*stack)->prev = node;
	(*stack)->prev->next = *stack;
	*stack = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	rra(t_stack **stack_a)
{
	revrotate(stack_a);
	update_index(*stack_a);
	ft_printf("rra\n");
}
