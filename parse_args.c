/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaktas <muaktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:54:36 by muaktas           #+#    #+#             */
/*   Updated: 2026/05/16 15:50:12 by muaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	error_exit(t_stack *stack)
{
	write(2, "Error\n", 6);
	if (stack)
		stack_free(stack);
	exit(1);
}

int	ft_checker(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ' || av[i][j] == '+'
				|| av[i][j] == '-'
				|| (av[i][j] >= '0' && av[i][j] <= '9'))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	has_duplicate(t_stack *stack)
{
	t_node	*check;
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		check = tmp->next;
		while (check)
		{
			if (tmp->value == check->value)
				return (1);
			check = check->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

t_stack	*parse_args(int ac, char **av, t_config *config)
{
	int		start;
	t_stack	*stack_a;

	start = parse_flags(ac, av, config);
	if (start >= ac)
		return (NULL);
	if (ft_checker(av + start))
		error_exit(NULL);
	stack_a = stack_new();
	if (!stack_a)
		return (NULL);
	ft_reader(av, start, stack_a);
	if (has_duplicate(stack_a))
		error_exit(stack_a);
	return (stack_a);
}
