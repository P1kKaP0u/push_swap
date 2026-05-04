/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 02:18:43 by mustafa           #+#    #+#             */
/*   Updated: 2026/05/04 18:10:07 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*temp;

	if (!from || !from->top)
		return ;
	temp = from->top;
	from->top = temp->next;
	if (from->top)
		from->top->prev = NULL;
	if (!to->top)
	{
		to->top = temp;
		to->bottom = temp;
		temp->next = NULL;
		temp->prev = NULL;
	}
	else
	{
		temp->next = to->top;
		temp->prev = NULL;
		to->top->prev = temp;
		to->top = temp;
	}
	from->size--;
	to->size++;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->top)
		return ;
	push(*stack_b, *stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->top)
		return ;
	push(*stack_a, *stack_b);
	ft_printf("pb\n");
}
