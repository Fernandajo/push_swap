/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stacks_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:39:03 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/23 19:08:04 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_ps(const char *str, t_stack	*stack)
{
	long	result;
	int		i;
	long	sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i++] - '0';
	}
	if ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		exit_error(stack, ERR_INV);
	if (((result * sign) > INT_MAX) || ((result * sign) < INT_MIN))
		exit_error(stack, ERR_MAX);
	return (result * sign);
}

int	checkdup(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (stack->next != NULL)
	{
		temp = stack;
		temp = temp->next;
		while (temp != NULL)
		{
			if (stack->number == temp->number)
				return (0);
			if (temp->next == NULL)
				break ;
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	count_nodes(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*create_b(t_stack **stack_a, int j)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	i = 0;
	while (i < j)
	{
		push(stack_a, &stack_b);
		ft_printf("pb\n");
		i++;
	}
	update_index(stack_b);
	update_index(*stack_a);
	return (stack_b);
}
