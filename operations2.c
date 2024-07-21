/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:25:03 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/21 22:48:39 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack	**stack_a)
{
	swap(stack_a);
	update_index(*stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack	**stack_b)
{
	swap(stack_b);
	update_index(*stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack	**stack_a, t_stack	**stack_b)
{
	swap(stack_a);
	swap(stack_b);
	update_index(*stack_a);
	update_index(*stack_b);
	ft_printf("ss\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	update_index(*stack_a);
	update_index(*stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	update_index(*stack_a);
	update_index(*stack_b);
	ft_printf("pb\n");
}
