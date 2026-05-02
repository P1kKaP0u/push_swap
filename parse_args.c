#include "ft_push_swap.h"

int    is_valid_number(const char *str)
{
    int i;
    
    i = 0;
    if (str[i] == '\0')
        return (0);
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[i] == '\0')
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int     has_duplicate(t_stack *stack, int value)
{
    t_node *current;
    
    current = stack->top;
    while (current != NULL)
    {
        if (current->value == value)
            return (1);
        current = current->next;
    }
    return (0);
}

void    error_exit(t_stack *stack)
{
    write(2, "Error\n", 6);
    if (stack)
        stack_free(stack);
    exit(1);
}

int     parse_flags(int argc, char **argv, t_config *config)
{
    int i;
    
    config->strategy = STRAT_ADAPTIVE;
    config->bench = 0;
    i = 1;
    while (i < argc)
    {
        if (argv[i][0] == '-' && argv[i][1] == '-')
        {
            if (ft_strncmp(argv[i], "--simple", 9) == 0)
                config->strategy = STRAT_SIMPLE;
            else if (ft_strncmp(argv[i], "--medium", 9) == 0)
                config->strategy = STRAT_MEDIUM;
            else if (ft_strncmp(argv[i], "--complex", 10) == 0)
                config->strategy = STRAT_COMPLEX;
            else if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
                config->strategy = STRAT_ADAPTIVE;
            else if (ft_strncmp(argv[i], "--bench", 8) == 0)
                config->bench = 1;
            else
                error_exit(NULL);
            i++;
        }
        else
            break;
    }
    return (i);
}

int ft_checker(char **av)
{
    int i;
    int j;

    i = 0;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] == ' ' || av[i][j] == '+'
                || av[i][j] == '-'
                || (av[i][j] >= '0' && av[i][j] <= '9'))
                j++;
            else
                return (1);
        }
        i++;
    }
    return (0);
}

int ft_spcchk(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

t_node  *ft_reader(char **av, int start)
{
    int     i;
    int     j;
    char    **tmp;
    t_node  *lst;
    t_node  *new;
    t_node  *head;  // BUG 1 FIX: başa alındı

    i = start;
    j = 0;
    lst = NULL;
    head = NULL;
    while (av[i])
    {
        if (ft_spcchk(av[i]))
        {
            j = 0;
            tmp = ft_split(av[i], ' ');
            while (tmp[j])
            {
                new = malloc(sizeof(t_node));
                if (!new)
                    return (NULL);
                if (!is_valid_number(tmp[j]))
                    error_exit(NULL);
                new->value = ft_atol(tmp[j]);
                new->next = NULL;
                if (!head)
                    head = new;
                else
                    lst->next = new;
                lst = new;
                j++;
            }
        }
        else
        {
            new = malloc(sizeof(t_node));
            if (!new)
                return (NULL);
            if (!is_valid_number(av[i]))
                error_exit(NULL);
            new->value = ft_atol(av[i]);
            if (new->value > 2147483647 || new->value < -2147483648)
                error_exit(NULL);
            new->next = NULL;
            if (!head)
                head = new;
            else
                lst->next = new;
            lst = new;
        }
        i++;
    }
    return (head);
}

t_stack *parse_args(int ac, char **av, t_config *config, t_node *lst_a)
{
    int     start;
    t_stack *stack_a;
    t_node  *tmp;
    int     size;

    start = parse_flags(ac, av, config);
    if (start >= ac)
        return (NULL);
    lst_a = ft_reader(av, start);  // BUG 2 FIX: ac kaldı, start eklendi
    if (!lst_a)
        return (NULL);
    stack_a = stack_new();
    if (!stack_a)
        return (NULL);
    stack_a->top = lst_a;
    tmp = lst_a;
    size = 0;
    while (tmp && tmp->next)
    {
        size++;
        tmp = tmp->next;
    }
    stack_a->bottom = tmp;
    stack_a->size = size + 1;  // BUG 3 FIX: son eleman da sayılıyor
    return (stack_a);
}