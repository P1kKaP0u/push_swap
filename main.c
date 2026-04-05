/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:58:03 by muaktas           #+#    #+#             */
/*   Updated: 2026/04/05 18:01:30 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>
#include "swap.c"
#include "push.c"


int	main()
{
	t_stack	*stack_a = stack_new();
	t_stack	*stack_b = stack_new();

	stack_push(stack_a, 23);
	stack_push(stack_a, 97);
	stack_push(stack_a, 4);
	stack_push(stack_a, 34);
	stack_push(stack_a, 29);
	stack_push(stack_a, 32);
	stack_push(stack_a, 3643234);
	stack_push(stack_a, 12);
	stack_push(stack_a, 123143);
	stack_push(stack_a, 34636);
	stack_push(stack_a, 124);


	//65-34-4-97-23

	
	// t_list	*min = find_min(stack_a);
	// t_list	*max = find_max(stack_a);
	// printf("EN GÜÇCUK DEĞER : %d, index: %d\n", min->value, find_index(min, stack_a));
	// printf("EN BÖYÜK DEĞER : %d, index: %d\n", max->value, find_index(max, stack_a));
	sort_simple(stack_a, stack_b);

	t_node *tmp = stack_a->top;

	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	stack_free(stack_a);

}
