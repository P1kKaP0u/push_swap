/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:34:29 by mustafa           #+#    #+#             */
/*   Updated: 2026/05/03 17:37:55 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node	*find_min(t_stack *stack)
{
	t_node	*tmp;
	t_node	*min;

	tmp = stack->top;
	if (!stack || !stack->top)
		return (NULL);
	min = tmp;
	while (tmp)
	{
		if (tmp->next != NULL && min->value > tmp->next->value)
			min = tmp->next;
		tmp = tmp->next;
	}
	return (min);
}

t_node	*find_max(t_stack *stack)
{
	t_node	*tmp;
	t_node	*max;

	if (!stack || !stack->top)
		return (NULL);
	tmp = stack->top;
	max = tmp;
	while (tmp)
	{
		if (tmp->next != NULL && max->value < tmp->next->value)
			max = tmp->next;
		tmp = tmp->next;
	}
	return (max);
}

unsigned int	find_index(t_node *node, t_stack *stack)
{
	t_node			*tmp;
	unsigned int	index;

	if (!node || !stack)
		return (-1);
	tmp = stack->top;
	index = 0;
	while (tmp)
	{
		if (tmp == node)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}
