/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa <mustafa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 02:20:58 by mustafa           #+#    #+#             */
/*   Updated: 2026/05/04 19:01:24 by mustafa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

void			sort_medium(t_stack *stack_a, t_stack *stack_b);
t_stack			*parse_args(int argc, char **argv, t_config *config,
					t_node *node);
void			ft_printf(char *str);
void			stack_push(t_stack *stack, int data);
void			stack_pop(t_stack *stack);
void			stack_free(t_stack *stack);
int				stack_is_sorted(t_stack *stack);
t_stack			*stack_new(void);
void			sa(t_stack **stack_a);
void			sb(t_stack **stack_b);
void			ss(t_stack **stack_a, t_stack **stack_b);
void			pa(t_stack **stack_a, t_stack **stack_b);
void			pb(t_stack **stack_a, t_stack **stack_b);
void			ra(t_stack *stack_a);
void			rb(t_stack *stack_b);
void			rr(t_stack *stack_a, t_stack *stack_b);
void			rra(t_stack *stack_a);
void			rrb(t_stack *stack_b);
void			rrr(t_stack *stack_a, t_stack *stack_b);
t_node			*find_min(t_stack *stack);
t_node			*find_max(t_stack *stack);
void			rank_normalize(t_stack *stack);
void			sort_simple(t_stack *stack_a, t_stack *stack_b);
void			sort_complex(t_stack *stack_a, t_stack *stack_b);
unsigned int	find_index(t_node *node, t_stack *stack);
void			sort_small(t_stack *stack_a, t_stack *stack_b);

#endif
