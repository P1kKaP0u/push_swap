#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef	struct s_stack
{
	t_list	*top;
	t_list	*bottom;
	int		size;
} 	t_stack;

void	ft_printf(char *str);
void	sa(t_stack **stack_a);

# endif
