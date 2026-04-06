#include "ft_push_swap.h"
#include <stdio.h>

static void sort_for_rank(int *numbers, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - 1 - i)
        {
            if ((numbers[j] > numbers[j + 1]))
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

static void map_to_list(int *numbers, t_stack *stack,int size)
{
    t_node  *tmp;
    int     i;

    tmp = stack->top;
    while (tmp != NULL)
    {   
        i = 0;
        while (i < size)
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
    t_node *tmp;
    int *numbers;
    int i;
	int	size;

    i = 0;
    tmp = stack->top;
    numbers = malloc(stack->size * sizeof(int));
	size = stack->size;
    if (!numbers)
        return ;
    while (tmp != NULL)
    {
        numbers[i] = tmp->value;
        i++;
        tmp = tmp->next;
    }
	sort_for_rank(numbers, size);
    map_to_list(numbers, stack, size);
    free(numbers);
}