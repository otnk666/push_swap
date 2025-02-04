/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:10:03 by skomatsu          #+#    #+#             */
/*   Updated: 2025/02/04 20:00:48 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_list **stack)
{
    int a;
    int b;
    int c;
    
    a = (*stack)->next->content;    
    b = (*stack)->next->next->content;
    c = (*stack)->prev->content;

    if(a > b && b < c && a < c)
        sa(stack);
    else if (a > b && b > c && a > c)
    {   
        sa(stack);
        rra(stack);
    }
    else if (a > b && b < c && a > c)
        ra(stack);
    else if (a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
    }
    else if (a < b && b > c && a > c)
        rra(stack);
}

void sort_five(t_list **stack_a, t_list **stack_b)
{
    t_list *min;
    while(ft_lstsize(*stack_a) > 3)
    {
        min = ft_stack_min(stack_a);
        push_min(stack_a, stack_b, min);
    }
    sort_three(stack_a);
    while(ft_lstsize(*stack_b) > 0)
        pa(stack_a, stack_b); 
}

static void ft_push_min(t_list **stack_a, t_list **stack_b, t_list *min)
{
    int min_count;
    int size;

    size = ft_lstsize(*stack_a);
    if(min_count <= size / 2)
    {
        while((*stack_a) -> next != min)
            ra(*stack_a);
    }
    else
    {
        while ((*stack_a) -> next != min)
            rra(*stack_a);
    }
    pb(stack_a,stack_b);
}


void sort(t_list **stack_a, t_list **stack_b)
{
    int size;
    size = ft_lstsize(*stack_a);

    if(size <= 3)
        sort_3(stack_a);
    else if(size <= 5)
        sort_five(stack_a,stack_b);
    else
        quick_sort(stack_a, stack_b);

}


t_list	*ft_stack_min(t_list **stack)
{
	t_list	*min;
	t_list	*current;

	min = (*stack) -> next;
	current = (*stack) -> next;
	while (current)
	{
		if (current->content < min->content)
			min = current;
		current = current->next;
	}
	return (min);
}
