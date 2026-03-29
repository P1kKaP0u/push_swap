/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:58:03 by muaktas           #+#    #+#             */
/*   Updated: 2026/04/05 17:11:01 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>
#include "swap.c"


int	main()
{
	t_stack	*stack_a = stack_new();
	t_stack *stack_b = stack_new();

	stack_push(stack_a, 345);


	stack_push(stack_b, 98);

	t_list *tmp_a;
	t_list *tmp_b;

	ss(&stack_a, &stack_b);
	tmp_a = stack_a->top;
	tmp_b = stack_b->top;
	printf("***STACK_A***\n");
	while (tmp_a)
	{
		printf("%d\n", tmp_a->value);
		tmp_a = tmp_a->next;
	}
	printf("***STACK_B***\n");
	while (tmp_b)
	{
		printf("%d\n", tmp_b->value);
		tmp_b = tmp_b->next;
	}

	stack_free(stack_a);
	stack_free(stack_b);

}