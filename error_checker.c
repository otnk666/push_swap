#include "push_swap.h"
#include "../libft/libft.h"

int stack_error(char *node)
{
    if (node == NULL)
        return (1);
    if (node->content == NULL)
        return (1);
    if (node->next == NULL)
        return (1);
    if (node->prev == NULL)
        return (1);
    return (0);
}   
