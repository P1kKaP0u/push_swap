/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 17:32:44 by mustafa           #+#    #+#             */
/*   Updated: 2026/05/13 22:01:08 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	stack->top = tmp->next;
	stack->top->prev = NULL;
	if (stack->top->next)
	{
		tmp->next = stack->top->next;
		stack->top->next->prev = tmp;
	}
	else
	{
		tmp->next = NULL;
		stack->bottom = tmp;
	}
	stack->top->next = tmp;
	tmp->prev = stack->top;
}

void	sa(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_a->size < 2 || stack_b->size < 2)
		return ;
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
