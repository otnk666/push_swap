#include "push_swap.h"
#include "../libft/libft.h"

int main(int argc, char *argv[])
{
    t_list *stack_a;
    t_list *stack_b;
    int i;

    if(argc < 2)
    {
        ft_printf("Error/n");
        return (NULL);
    }

    stack_a = create_sentinel();
    stack_b = create_sentinel();
    addstack(&stack_a,argc, argv);

    sort(stack_a, stack_b);

    while(stack_a)
    {
        
    }

}

t_list *create_sentinel(void)
{
    t_list *sentinel;
    sentinel = ft_lstnew(0);
    if (!sentinel)
        return (NULL);
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
    return (sentinel);
    }

void    addstack(t_list **stack, int argc, char *argv[])
{
    int i;
    int temp;
    t_list *new_node;

    i = 1;
    while(i < argc)
    {
        temp = ft_atoi(argv[i]);
        new_node = ft_lstnew(temp);
        ft_lstadd_back(stack, new_node);
        i++;
    }
}

