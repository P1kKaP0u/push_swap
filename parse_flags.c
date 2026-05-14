/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 05:07:26 by mustafa           #+#    #+#             */
/*   Updated: 2026/05/14 05:21:38 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	handle_flag(char **arg, t_config *config,
	int *strategy_set, int i)
{
	if (ft_strncmp(arg[i], "--bench", 8) == 0)
	{
		config->bench = 1;
		return (1);
	}
	else if (ft_strncmp(arg[i], "--simple", 9) == 0)
		config->strategy = STRAT_SIMPLE;
	else if (ft_strncmp(arg[i], "--medium", 9) == 0)
		config->strategy = STRAT_MEDIUM;
	else if (ft_strncmp(arg[i], "--complex", 10) == 0)
		config->strategy = STRAT_COMPLEX;
	else if (ft_strncmp(arg[i], "--adaptive", 11) == 0)
		config->strategy = STRAT_ADAPTIVE;
	else
		return (0);
	if (*strategy_set)
		error_exit(NULL);
	*strategy_set = 1;
	return (1);
}

int	parse_flags(int argc, char **argv, t_config *config)
{
	int	i;
	int	strategy_set;

	strategy_set = 0;
	config->strategy = STRAT_ADAPTIVE;
	config->bench = 0;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (handle_flag(argv, config, &strategy_set, i))
			{
				i++;
				continue ;
			}
			else
				error_exit(NULL);
		}
		else
			break ;
	}
	return (i);
}
