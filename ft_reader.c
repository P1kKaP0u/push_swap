/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 17:58:03 by muaktas           #+#    #+#             */
/*   Updated: 2026/05/14 06:57:28 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
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

t_node	*ft_reader(char **av, int start)
{
	int		i;
	int		j;
	long	val;
	char	**tmp;
	t_node	*lst;
	t_node	*new;
	t_node	*head;

	i = start;
	j = 0;
	lst = NULL;
	head = NULL;
	while (av[i])
	{
		if (ft_spcchk(av[i]))
		{
			j = 0;
			tmp = ft_split(av[i], ' ');
			while (tmp[j])
			{
				new = malloc(sizeof(t_node));
				if (!new)
					return (NULL);
				if (!is_valid_number(tmp[j]))
					error_exit(NULL);
				val = ft_atol(tmp[j]);
				if (val > 2147483647 || val < -2147483648)
					error_exit(NULL);
				new->value = (int)val;
				new->next = NULL;
				new->prev = lst;
				if (!head)
				{
					head = new;
					new->prev = NULL;
				}
				else
					lst->next = new;
				lst = new;
				j++;
			}
			j = 0;
			while (tmp[j])
				free(tmp[j++]);
			free(tmp);
		}
		else
		{
			new = malloc(sizeof(t_node));
			if (!new)
				return (NULL);
			if (!is_valid_number(av[i]))
				error_exit(NULL);
			val = ft_atol(av[i]);
			if (val > 2147483647 || val < -2147483648)
				error_exit(NULL);
			new->value = (int)val;
			new->next = NULL;
			new->prev = lst;
			if (!head)
			{
				head = new;
				new->prev = NULL;
			}
			else
				lst->next = new;
			lst = new;
		}
		i++;
	}
	return (head);
}
