/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:56 by skomatsu          #+#    #+#             */
/*   Updated: 2025/02/12 17:53:22 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void push_all_to_b(t_stack **stack_a, t_stack **stack_b) {
    while (ft_stacksize(*stack_a) > 0)
        pb(stack_a, stack_b);
}

void push_all_to_a(t_stack **stack_a, t_stack **stack_b) {
    while (ft_stacksize(*stack_b) > 0)
        pa(stack_a, stack_b);
}

void quick_sort_a(t_stack **stack_a, t_stack **stack_b) {
    if (ft_stacksize(*stack_a) <=1 || ft_is_sorted_AO(*stack_a))
		return;
	
	t_stack *pivot = (*stack_a)->next;
    int size = ft_stacksize(*stack_a), i = 0;


    while (i < size) {
        if ((*stack_a)->next->content < pivot->content) {
            pb(stack_a, stack_b);
        } else {
            ra(stack_a);
        }
		i++;
    }

	if((*stack_a)->next->content == pivot->content)
		pb(stack_a, stack_b);
	quick_sort_b(stack_a, stack_b);
	quick_sort_a(stack_a, stack_b);
	if (ft_is_sorted_AO(*stack_a) && ft_is_sorted_DO(*stack_b))
	{
		push_all_to_a(stack_a, stack_b);
		return;
	}

}

void quick_sort_b(t_stack **stack_a, t_stack **stack_b) {

	if (ft_stacksize(*stack_b) <= 1 || ft_is_sorted_DO(*stack_b))
	{	
		quick_sort_a(stack_a, stack_b);
		return;
	}
    
	int pivot = (*stack_b)->next->next->content;
    int size = ft_stacksize(*stack_b), i = 0;
    
    while (i < size) {
        if ((*stack_b)->next->content > pivot) {
            pa(stack_a, stack_b);
        } else {
            rb(stack_b);
        }
		i++;
    }
    if((*stack_b)->next->content == pivot)
		pa(stack_a, stack_b);
	
	quick_sort_a(stack_a, stack_b);
	
}

int	ft_is_sorted_AO(t_stack *stack)
{
	t_stack *current;

	if(!stack || !stack->next)
		return (1);
	current = stack->next;

	while(current -> next != stack)
	{
		if(current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_is_sorted_DO(t_stack *stack)
{
	t_stack *current;

	if(!stack || !stack->next)
		return (1);
	current = stack->next;

	while(current->next != stack)
	{
		if(current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
