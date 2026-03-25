/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaktas <muaktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:31:05 by muaktas           #+#    #+#             */
/*   Updated: 2026/03/25 18:07:28 by muaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*stack_new(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	new_stack->size = 0;
	return (new_stack);
}

void	stack_push(t_stack *stack, int data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->value = data;
	new_node->prev = NULL;
	new_node->next = stack->top;
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bottom = new_node;
		stack->size = stack->size + 1;
	}
	else
	{
		stack->top->prev = new_node;
		stack->top = new_node;
		stack->size = stack->size + 1;
	}
}

void	stack_pop(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = stack->top->next;
		stack->top->prev = NULL;
	}
	free(tmp);
	stack->size = stack->size - 1;
}

int	stack_is_sorted(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top;
	while (tmp && tmp->next)
	{	
		if (tmp->value > tmp->next->value)
		{	
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void stack_free(t_stack *stack)
{

	while (stack->top)
	{
		stack_pop(stack);
	}
	free(stack);
}