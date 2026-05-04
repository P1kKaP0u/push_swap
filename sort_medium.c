/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 02:04:16 by mustafa           #+#    #+#             */
/*   Updated: 2026/05/04 02:04:28 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	ft_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static void	bring_max_to_top(t_stack *stack_b)
{
	t_node	*max;
	int		max_index;
	int		half;

	max = find_max(stack_b);
	max_index = find_index(max, stack_b);
	half = stack_b->size / 2;
	if (max_index <= half)
	{
		while (stack_b->top != max)
			rb(stack_b);
	}
	else
	{
		while (stack_b->top != max)
			rrb(stack_b);
	}
}

static void	push_chunk_to_b(t_stack **stack_a, t_stack **stack_b,
		int chunk_min, int chunk_max)
{
	int	size;
	int	val;

	size = (*stack_a)->size;
	while (size > 0)
	{
		val = (*stack_a)->top->value;
		if (val >= chunk_min && val <= chunk_max)
			pb(stack_a, stack_b);
		else
			ra(*stack_a);
		size--;
	}
}

void	sort_medium(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	total;

	rank_normalize(stack_a);
	total = stack_a->size;
	chunk_size = ft_sqrt(total);
	chunk_min = 0;
	chunk_max = chunk_size - 1;
	while (chunk_min < total)
	{
		if (chunk_max >= total)
			chunk_max = total - 1;
		push_chunk_to_b(&stack_a, &stack_b, chunk_min, chunk_max);
		chunk_min = chunk_max + 1;
		chunk_max = chunk_min + chunk_size - 1;
	}
	while (stack_b->size > 0)
	{
		bring_max_to_top(stack_b);
		pa(&stack_a, &stack_b);
	}
}
