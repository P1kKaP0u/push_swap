/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaktas <muaktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:58:03 by muaktas           #+#    #+#             */
/*   Updated: 2026/03/25 19:58:37 by muaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "stack_utils.c"
#include <stdio.h>
#include "swap.c"


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