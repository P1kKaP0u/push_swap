#include "ft_push_swap.h"

static unsigned int countBits(unsigned int n)
{
   unsigned int count = 0;
   while (n)
   {
        count++;
        n >>= 1;
    }
    return count;
}

void	sort_complex(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	bit;
	int				value;
	int				size;

	rank_normalize(stack_a);
	bit = 0;
	while (bit < countBits(find_max(stack_a)->value) && stack_is_sorted(stack_a) == 0)
	{
		size = stack_a->size;
		while (size > 0)
		{
			value = stack_a->top->value;
			if ((value >> bit) & 1)
				ra(stack_a);
			else
				pb(&stack_a, &stack_b);
			size--;
		}
		while (stack_b->size > 0)
			pa(&stack_a, &stack_b);
		bit++;
	}
}
