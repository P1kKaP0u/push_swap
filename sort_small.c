/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:44:57 by mustafa           #+#    #+#             */
/*   Updated: 2026/05/03 17:46:44 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_2(t_stack *stack)
{
	if ((stack)->top->value > (stack)->top->next->value)
	{
		sa(stack);
	}
}

void	sort_3(t_stack *stack)
{
	t_node			*max;
	unsigned int	max_index;

	max = find_max(stack);
	while (find_index(max, stack) != 2)
	{
		if (max_index <= (unsigned int)stack->size / 2)
			ra(stack);
		else
			rra(stack);
	}
	sort_2(stack);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	t_node			*min;
	unsigned int	min_index;

	if (stack_a->size == 2)
		sort_2(stack_a);
	if (stack_a->size == 3)
		sort_3(stack_a);
	min = find_min(stack_a);
	while (find_index(min, stack_a) != 0)
	{
		if (min_index <= (unsigned int)stack_a->size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_small(stack_a, stack_b);
	pa(stack_a, stack_b);
}
