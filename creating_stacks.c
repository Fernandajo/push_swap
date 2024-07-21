/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjoestin <fjoestin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:45:39 by fjoestin          #+#    #+#             */
/*   Updated: 2024/04/23 19:00:07 by fjoestin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*creating_stack(char **args, int i)
{
	t_stack	*stack;
	t_stack	*temp;
	long	nbr;
	int		j;

	j = i;
	stack = NULL;
	while (args[j])
	{
		nbr = ft_atoi_ps(args[j], stack);
		temp = createnode(nbr);
		ft_lstadd_back_ps(&stack, temp);
		j++;
	}
	if (i == 0)
		free_matrix(args);
	update_index(stack);
	if (!checkdup(stack))
		exit_error(stack, ERR_DUP);
	return (stack);
}

t_stack	*createnode(long nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(1);
	new->number = nbr;
	new->index = INT_MAX;
	new->cost = INT_MAX;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = ft_lstlast_ps(*lst);
	if (!last)
	{
		*lst = new;
		new->prev = NULL;
	}
	else
	{
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	t_stack	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

void	update_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}
