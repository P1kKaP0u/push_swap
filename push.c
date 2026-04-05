#include "ft_push_swap.h"

void    push(t_stack *from, t_stack *to)
{
    t_node  *temp;

    temp = from->top;
    from->top = temp->next;
    if (from->top)
        from->top->prev = NULL;
    temp->next = to->top;
    temp->prev = NULL;
    if (to->top)
        to->top->prev = temp;
    to->top = temp;
    from->size = from->size - 1;
    to->size = to->size + 1;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{	
	if (!stack_b || !*stack_b)
		return ;
    push(*stack_b, *stack_a);
    ft_printf("pa\n");
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{   

    if (!stack_a || !*stack_a)
        return;
    push(*stack_a, *stack_b);
    ft_printf("pb\n");
}
