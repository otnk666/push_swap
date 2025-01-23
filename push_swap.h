#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    int             content;
    struct s_list   *next;
    struct s_list   *prev;
}               t_list;

/* command */
void    ft_command(t_list **stack_a, t_list **stack_b, char *line);
void    create_sentinel(t_list **stack);

/* stack operations */
void    sa(t_list **stack_a);
void    sb(t_list **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);
void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_a, t_list **stack_b);
void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);
void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);

/* sorting algorithms */
void    sort(t_list **stack_a, t_list **stack_b);
void    sort_three(t_list **stack);
void    sort_five(t_list **stack_a, t_list **stack_b);
void    quick_sort(t_list **stack_a, t_list **stack_b);

/* utility functions */
int     ft_lstsize(t_list *lst);
t_list  *ft_stack_min(t_list **stack);
int     ft_stack_min_count(t_list **stack, t_list *min);
void    push_min(t_list **stack_a, t_list **stack_b, t_list *min);

/* error checker */
int     stack_error(t_list *node);

#endif
