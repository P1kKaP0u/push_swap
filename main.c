/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaktas <muaktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:58:03 by muaktas           #+#    #+#             */
/*   Updated: 2026/04/06 20:50:19 by muaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int	main()
{
	t_stack	*stack_a = stack_new();
	t_stack	*stack_b = stack_new();

	// stack_push(stack_a, 13124142);
	// stack_push(stack_a, 97);
	// stack_push(stack_a, 4);
	// stack_push(stack_a, 34);
	// stack_push(stack_a, 29);
	// stack_push(stack_a, 3643234);
	// stack_push(stack_a, 12);
	// stack_push(stack_a, 0);
	// stack_push(stack_a, 123143);

	int i = 0;
	while (i < 600)
	{
		stack_push(stack_a, i);
		i++;
	}
	


	//65-34-4-97-23

	
	// t_list	*min = find_min(stack_a);
	// t_list	*max = find_max(stack_a);
	// printf("EN GÜÇCUK DEĞER : %d, index: %d\n", min->value, find_index(min, stack_a));
	// printf("EN BÖYÜK DEĞER : %d, index: %d\n", max->value, find_index(max, stack_a));
	sort_complex(stack_a, stack_b);
	// sort_simple(stack_a, stack_b);


	t_node *tmp = stack_a->top;

	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	stack_free(stack_a);
	stack_free(stack_b);

}
