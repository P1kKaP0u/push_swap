/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 20:54:36 by muaktas           #+#    #+#             */
/*   Updated: 2026/05/14 07:33:11 by mustafa          ###   ########.fr       */
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

static void	finale_stack(t_stack *stack, t_node *lst)
{
	t_node	*tmp;
	int		size;

	stack->size = 0;
	stack->top = lst;
	tmp = lst;
	size = 0;
	while (tmp)
	{
		size++;
		if (tmp->next == NULL)
			stack->bottom = tmp;
		tmp = tmp->next;
	}
	stack->size = size;
}

t_stack	*parse_args(int ac, char **av, t_config *config, t_node *lst_a)
{
	int		start;
	t_stack	*stack_a;

	start = parse_flags(ac, av, config);
	if (start >= ac)
		return (NULL);
	if (ft_checker(av + start))
		error_exit(NULL);
	lst_a = ft_reader(av, start);
	if (!lst_a)
		return (NULL);
	stack_a = stack_new();
	if (!stack_a)
		return (NULL);
	finale_stack(stack_a, lst_a);
	if (has_duplicate(stack_a))
		error_exit(stack_a);
	return (stack_a);
}
