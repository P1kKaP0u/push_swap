/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:46:55 by muhakgul          #+#    #+#             */
/*   Updated: 2026/04/05 17:59:36 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int    is_valid_number(const char *str)
{
    int i;
    
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

int     has_duplicate(t_stack *stack, int value)
{
    t_node *current;
    
    current = stack->top;
    while (current != NULL)
    {
        if (current->value == value)
            return (1);
        current = current->next;
    }
    return (0);
}

int     parse_flags(int argc, char **argv, t_config *config)
{
    
    int i;
    
    config->strategy = STRAT_ADAPTIVE;
    config->bench = 0;
    i = 1;
    while (i < argc)
    {
        if (argv[i][0] == '-' && argv[i][1] == '-')
        {
            if (ft_strncmp(argv[i], "--simple", 9) == 0)
                config->strategy = STRAT_SIMPLE;
            else if (ft_strncmp(argv[i], "--medium", 9) == 0)
                config->strategy = STRAT_MEDIUM;
            else if (ft_strncmp(argv[i], "--complex", 10) == 0)
                config->strategy = STRAT_COMPLEX;
            else if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
                config->strategy = STRAT_ADAPTIVE;
            else if (ft_strncmp(argv[i], "--bench", 8) == 0)
                config->bench = 1;
            else
                error_exit(NULL);
            i++;
        }
        else
            break;
    }
    return (i);
}

void    error_exit(t_stack *stack)
{
    write(2, "Error\n", 6);
    if (stack)
        stack_free(stack);
    exit(1);
}

t_stack     *parse_args(int argc, char **argv, t_config *config)
{
    int i;
    int start;
    long num;
    
    t_stack *stack_a;
    start = parse_flags(argc, argv, config);
    if (start >= argc)
        return (NULL);
    stack_a = stack_new();
    if (!stack_a)
        return (NULL);
    i = argc - 1;
    while (i >= start)
    {
        if (!is_valid_number(argv[i]))
            error_exit(stack_a);
        num = ft_atol(argv[i]);
        if (num > 2147483647 || num < -2147483648)
            error_exit(stack_a);
        if (has_duplicate(stack_a, (int)num))
            error_exit(stack_a);
        stack_push(stack_a, (int)num);
        i--;
    }
    return (stack_a);
}
