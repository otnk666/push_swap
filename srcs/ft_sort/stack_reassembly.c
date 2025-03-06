
#include "push_swap.h"
#include "../libft/libft.h"

void reassemble_stack(t_stack **stack_a, t_stack **stack_b) {
    while (ft_stacksize(*stack_b) > 0) {
        pa(stack_a, stack_b);
    }
    t_stack *min_node = ft_min(*stack_a); //最小値のノードを見つける関数
    while ((*stack_a)->next != min_node)
    {
        ra(stack_a);
    }
}

t_stack *ft_min(t_stack *stack)
{
    t_stack *current;
    t_stack *min;

    if(!stack || !stack->next)
        return (NULL);
    current = stack->next;
    min = stack->next;
    while(current -> next != stack)
    {
        if(current->content < min->content)
            min = current;
        current = current->next;
    }
    return (min);
}