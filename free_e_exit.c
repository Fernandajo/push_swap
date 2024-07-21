/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_e_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:58:45 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/23 19:01:12 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_stack *stack, char *msg)
{
	ft_printf("%s", msg);
	free_stack(stack);
	exit(0);
}

void	free_stack(t_stack *stack_a)
{
	t_stack	*temp;

	if (!stack_a)
		return ;
	while (stack_a != NULL)
	{
		temp = stack_a->next;
		free(stack_a);
		stack_a = temp;
	}
	free(temp);
}

int	count_lines_matrix(char **matrix)
{
	int	lines;
	int	i;

	i = 0;
	lines = 0;
	while (matrix[i])
	{
		lines++;
		i++;
	}
	return (lines);
}

void	free_matrix(char **matrix)
{
	int	i;
	int	lines;

	lines = count_lines_matrix(matrix);
	i = 0;
	while (i < lines)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
