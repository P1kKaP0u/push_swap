#include "ft_push_swap.h"

static void min_value_to_top(t_stack *stack_a)
{
    t_node  *min_value;
    int min_index;

    min_value = find_min(stack_a);
    min_index = find_index(min_value, stack_a);
    if (min_index <= stack_a->size/2)
    {
        while (find_index(min_value, stack_a) != 0)
        {
            ra(stack_a);
        }
    }
    else
    {
        while (find_index(min_value, stack_a) != 0)
        {
            rra(stack_a);
        }
    }
}

void    sort_simple(t_stack *stack_a, t_stack *stack_b)
{
    while (stack_a->size > 0)
    {
        min_value_to_top(stack_a);
        pb(&stack_a, &stack_b);
    }
    while (stack_b->size > 0)
    {
        pa(&stack_a, &stack_b);
    }
}