#include "ft_push_swap.h"
#include "utils.c"

static void	swap(t_stack *stack)
{	
	t_node *tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	stack->top = tmp->next;
	stack->top->prev = NULL;
	if (stack->top->next)
	{
		tmp->next = stack->top->next;
		stack->top->next->prev = tmp;
	}
	else
		tmp->next = NULL;
	stack->top->next = tmp;
	tmp->prev = stack->top;
}

void	sa(t_stack **stack_a)
{	
	if (!stack_a || !*stack_a)
		return ;
	swap(*stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	swap(*stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{	
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	swap(*stack_a);
	swap(*stack_b);
	ft_printf("ss\n");
}