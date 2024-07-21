/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:00:08 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/23 16:09:56 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	t_stack	*head;

	head = *lst;
	if (lst)
	{
		if (head)
		{
			new->next = head;
			head->prev = new;
		}
		new->prev = NULL;
		*lst = new;
	}
	new->next = lst[0];
	*lst = new;
}

void	find_cost(t_stack **stack)
{
	t_stack	*temp;
	int		c;
	int		total;

	c = 0;
	temp = *stack;
	total = count_nodes(*stack);
	while (*stack)
	{
		if ((*stack)->index == (total / 2))
		{
			(*stack)->cost = c;
			c = (c * (-1));
			if (total % 2 == 0)
				c++;
			*stack = (*stack)->next;
		}
		if ((*stack) == NULL)
			break ;
		(*stack)->cost = c++;
		*stack = (*stack)->next;
	}
	*stack = temp;
}

void	find_neighbour(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*ret;
	t_stack	*temp;
	int		diff;
	int		low;

	ret = *stack_a;
	while (*stack_a != NULL)
	{
		low = lowest_value((*stack_a), (*stack_b));
		diff = 0;
		temp = *stack_b;
		while (temp != NULL)
		{
			diff = difference((*stack_a)->number, temp->number);
			if (diff == low)
			{
				(*stack_a)->neigh = temp;
				break ;
			}
			temp = temp->next;
		}
		(*stack_a)->sumop = sum_op(*stack_a);
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = ret;
}

int	lowest_value(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;
	int		low;
	int		diff;

	temp = stack_b;
	low = INT_MAX;
	diff = 0;
	while (temp != NULL)
	{
		diff = difference(stack_a->number, temp->number);
		if (low > diff)
			low = diff;
		temp = temp->next;
	}
	return (low);
}

int	difference(int a, int b)
{
	int	ret;

	if (a < 0 && b < 0)
		ret = (a * (-1)) - (b * (-1));
	else if (a > 0 && b > 0)
		ret = a - b;
	else
		ret = a - b;
	if (ret < 0)
		ret = (ret * (-1));
	return (ret);
}
