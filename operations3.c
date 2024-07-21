/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:04:29 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/21 22:48:48 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	update_index(*stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	update_index(*stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	update_index(*stack_a);
	update_index(*stack_b);
	ft_printf("rr\n");
}

void	rrb(t_stack **stack_b)
{
	revrotate(stack_b);
	update_index(*stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	revrotate(stack_a);
	revrotate(stack_b);
	update_index(*stack_a);
	update_index(*stack_b);
	ft_printf("rrr\n");
}
