/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:58:03 by muaktas           #+#    #+#             */
/*   Updated: 2026/04/05 17:15:00 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>
#include "swap.c"
#include "push.c"


int	main()
{
	t_stack	*stack_a = stack_new();

	stack_push(stack_a, -23);
	stack_push(stack_a, 97);
	stack_push(stack_a, 4);
	stack_push(stack_a, -34);
	stack_push(stack_a, 65);

	// t_list	*min = find_min(stack_a);
	// t_list	*max = find_max(stack_a);
	// printf("EN GÜÇCUK DEĞER : %d, index: %d\n", min->value, find_index(min, stack_a));
	// printf("EN BÖYÜK DEĞER : %d, index: %d\n", max->value, find_index(max, stack_a));
	t_list *tmp = stack_a->top;

	while (tmp)
	{
		printf("normal değer: %d\n", tmp->value);
		tmp = tmp->next;
	}
	rank_normalize(stack_a);
	t_list *tmp1 = stack_a->top;

	while (tmp1)
	{
		printf("yeni değer index: %d\n", tmp1->value);
		tmp1 = tmp1->next;
	}
	

	stack_free(stack_a);

}
