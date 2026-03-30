#include "ft_push_swap.h"

t_list  *find_min(t_stack *stack)
{
    t_list  *tmp;
    t_list  *min;

    tmp = stack->top;
    if (!stack || !stack->top)
	    return (NULL);
    min = tmp;
    while (tmp)
    {
        if (tmp->next != NULL && min->value > tmp->next->value)
            min = tmp->next;
        tmp = tmp->next;
    }
    return (min);
}

t_list  *find_max(t_stack *stack)
{
    t_list  *tmp;
    t_list  *max;

    if (!stack || !stack->top)
	    return (NULL);
    tmp = stack->top;
    max = tmp;
    while (tmp)
    {
        if (tmp->next != NULL && max->value < tmp->next->value)
            max = tmp->next;
        tmp = tmp->next;
    }
    return (max);
}

unsigned int    find_index(t_list *node, t_stack *stack)
{
    t_list          *tmp;
    unsigned int    index;

    if (!node || !stack)
	    return (-1);
    tmp = stack->top;
    index = 0;
    while (tmp)
    {
        if (tmp == node)
            return (index);
        tmp = tmp->next;
        index++;
    }
    return (-1);
}
