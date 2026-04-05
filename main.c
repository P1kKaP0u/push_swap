/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakgul <muhakgul@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:58:03 by muaktas           #+#    #+#             */
/*   Updated: 2026/03/30 03:28:09 by muhakgul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int	main()
{
	t_stack	*stck = stack_new();

	stack_push(stck, 345);
	stack_push(stck, 56);
	t_list *temp;
	
	ss(&stck, &stck);
	temp = stck->top;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	stack_free(stck);

}