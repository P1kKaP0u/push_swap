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

double compute_disorder(t_stack *stack_a)
{
	int total_inversions = 0;
	int max_inversions = 0;

	t_node *head = stack_a->top;
	t_node *tmp;
	while(head->next)
	{
		tmp = head->next;
		while(tmp)
		{
			if(head->value > tmp->value)
				total_inversions++;
			tmp = tmp->next;
		}
		head = head->next;
	}
	max_inversions = (stack_a->size * (stack_a->size -1)) / 2;
	return ((double)total_inversions / (double)max_inversions);
}

void	exe_strategy(t_stack *stack_a, t_stack *stack_b, t_config *config)
{
		double disorder;

		if (config->strategy == STRAT_ADAPTIVE)
		{
			disorder = compute_disorder(stack_a);
			if (disorder < 0.2)
				config->strategy = STRAT_SIMPLE;
			else if (disorder < 0.5)
				config->strategy = STRAT_MEDIUM;
			else
				config->strategy = STRAT_COMPLEX;
		}
		if (config->strategy == STRAT_SIMPLE)
			sort_simple(stack_a, stack_b);
		else if (config->strategy == STRAT_MEDIUM)
			sort_medium(stack_a, stack_b);
		else if (config->strategy == STRAT_COMPLEX)
			sort_complex(stack_a, stack_b);
}

int	main(int ac, char **av)
{
    t_node      *lst_a;
    t_config    config;
    t_stack     *stack_a;
    t_stack     *stack_b;

    lst_a = NULL;
    stack_a = parse_args(ac, av, &config, lst_a);
    if (!stack_a)
        return (0);
    stack_b = stack_new();

	exe_strategy(stack_a, stack_b, &config);
    stack_free(stack_a);
    stack_free(stack_b);
    return (0);
}
