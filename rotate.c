/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakgul <muhakgul@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 03:59:18 by muhakgul          #+#    #+#             */
/*   Updated: 2026/04/05 15:32:47 by muhakgul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void rotate(t_stack *stack)
{
    t_list *tmp;

    
    if (stack->size < 2)
        return;
    tmp = stack->top;
    stack->top = tmp->next;
    stack->top->prev = NULL;
    
    stack->bottom->next = tmp;
    tmp->prev = stack->bottom;
    tmp->next = NULL;
    
    stack->bottom = tmp;
}

void    ra(t_stack *stack_a)
{
    if (!stack_a)
        return;
    rotate(stack_a);
    ft_printf("ra\n");
}

void    rb(t_stack *stack_b)
{
    if (!stack_b)
        return;
    rotate(stack_b);
    ft_printf("rb\n");
}

void    rr(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b)
        return;
    rotate(stack_a);
    rotate(stack_b);
    ft_printf("rr\n");
}