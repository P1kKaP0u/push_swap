/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakgul <muhakgul@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 15:33:57 by muhakgul          #+#    #+#             */
/*   Updated: 2026/04/05 16:57:24 by muhakgul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void reverse_rotate(t_stack *stack)
{
    t_list *tmp;
    
    if (stack->size < 2)
        return;
    tmp = stack->bottom;
    stack->bottom = tmp->prev;
    stack->bottom-next = NULL;
    tmp->prev = NULL;

    tmp->next = stack->top;
    stack->top->prev = tmp;

    stack->top = tmp;
}

void    rra(t_stack *stack_a)
{
    if (!stack_a)
        return;
    reverse_rotate(stack_a);
    ft_printf("rra\n");
}

void    rrb(t_stack *stack_b)
{
    if(!stack_b)
        return;
    reverse_rotate(stack_b);
    ft_printf("rrb\n");
}

void    rrr(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b)
        return;
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_printf("rrr\n");
}