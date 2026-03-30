#include "ft_push_swap.h"

static void sort_for_rank(int *numbers)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (numbers[i])
    {
        j = 0;
        while (numbers[j])
        {
            if (numbers[j + 1] && (numbers[j] > numbers[j + 1]))
            {
                tmp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

static void map_to_list(int *numbers, t_stack *stack)
{
    t_list  *tmp;
    int     i;

    tmp = stack->top;
    while (tmp)
    {   
        i = 0;
        while (numbers[i])
        {
            if (tmp->value == numbers[i])
            {
                tmp->value = i;
            }
            i++;
        }
        tmp = tmp->next;
    }
}

void    rank_normalize(t_stack *stack)
{
    t_list *tmp;
    int *numbers;
    int i;

    i = 0;
    tmp = stack->top;
    numbers = malloc(stack->size * sizeof(int));
    if (!numbers)
        return ;
    while (tmp)
    {
        numbers[i] = tmp->value;
        i++;
        tmp = tmp->next;
    }
    i = 0;
    sort_for_rank(numbers);
    map_to_list(numbers, stack);
    free(numbers);
}