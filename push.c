#include "ft_push_swap.h"

void push(t_stack *from, t_stack *to)
{
    t_node *temp;

    if (!from || !from->top)
        return;

    temp = from->top;
    from->top = temp->next;

    if (from->top)
        from->top->prev = NULL;

    // to empty stack case
    if (!to->top)
    {
        to->top = temp;
        to->bottom = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else
    {
        temp->next = to->top;
        temp->prev = NULL;
        to->top->prev = temp;
        to->top = temp;
    }

    from->size--;
    to->size++;
}
void pa(t_stack **a, t_stack **b)
{
    if (!b || !*b || !(*b)->top)
        return;

    push(*b, *a);
    ft_printf("pa\n");
}

void pb(t_stack **a, t_stack **b)
{
    if (!a || !*a || !(*a)->top)
        return;

    push(*a, *b);
    ft_printf("pb\n");
}
