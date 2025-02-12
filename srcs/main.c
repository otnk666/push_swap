/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:27:03 by skomatsu          #+#    #+#             */
/*   Updated: 2025/02/10 20:28:25 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "../libft/libft.h"

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    if(argc < 2)
    {
        ft_printf("Error\n");
        return (0);
    }

    create_sentinel(&stack_a);
    create_sentinel(&stack_b);
    if(!stack_a || !stack_b)
        return (0);
    addstack(&stack_a,argc, argv);
    sort(&stack_a, &stack_b);
    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
    return (0);
}

void	create_sentinel(t_stack **stack)
{
    t_stack *sentinel;
    sentinel = ft_stacknew(0);
    if (!sentinel)
        return;
    sentinel->next = sentinel;
    sentinel->prev = sentinel;
    *stack = sentinel;
}

void    addstack(t_stack **stack, int argc, char *argv[])
{
    int i;
    int temp;
    t_stack *new_node;

    i = 1;
    while(i < argc)
    {
        temp = ft_atoi(argv[i]);
        new_node = ft_stacknew(temp);
        if(!new_node)
            return;
        ft_stackadd_back(stack, new_node);
        i++;
    }
}

void ft_free_stack(t_stack **stack)
{
    t_stack *current;
    t_stack *sentinel;
    t_stack *next;


    sentinel = *stack;
    current = (*stack) -> next;
    while(current != sentinel)
    {
        next = current->next;
        free(current);
        current = next;    
    }
    free(sentinel);
    *stack = NULL;
}

