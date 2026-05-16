/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muaktas <muaktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:58:03 by muaktas           #+#    #+#             */
/*   Updated: 2026/05/16 15:51:36 by muaktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_spcchk(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static long	parse_value(char *str)
{
	long	val;

	if (!is_valid_number(str))
		error_exit(NULL);
	val = ft_atol(str);
	if (val > 2147483647 || val < -2147483648)
		error_exit(NULL);
	return (val);
}

static void	free_split(char **tmp)
{
	int	i;

	i = 0;
	if (!tmp)
		return ;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void	ft_reader(char **av, int start, t_stack *stack)
{
	int		i;
	int		j;
	char	**tmp;

	i = start;
	while (av[i])
	{
		if (ft_spcchk(av[i]))
		{
			tmp = ft_split(av[i], ' ');
			j = 0;
			while (tmp[j])
			{
				stack_add_back(stack, (int)parse_value(tmp[j]));
				j++;
			}
			free_split(tmp);
		}
		else
			stack_add_back(stack, (int)parse_value(av[i]));
		i++;
	}
}
