/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:44:38 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/04 17:49:05 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	while (ft_stacksize(*stack_a) > 3)
	{
		min = ft_stack_min(stack_a);
		ft_push_min(stack_a, stack_b, min);
	}
	sort_three_a(stack_a);
	while (ft_stacksize(*stack_b) > 0)
		pa(stack_a, stack_b);
}

void	ft_push_min(t_stack **stack_a, t_stack **stack_b, t_stack *min)
{
	int	min_count;
	int	size;

	size = ft_stacksize(*stack_a);
	min_count = ft_stack_min_count(stack_a);
	if (min_count <= size / 2)
	{
		while ((*stack_a)->next != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->next != min)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

int	ft_stack_min_count(t_stack **stack)
{
	t_stack	*current;
	int		min_value;
	int		min_index;
	int		current_count;

	current = (*stack)->next;
	min_value = current->content;
	current_count = 1;
	while (current != *stack)
	{
		if (min_value > current->content)
		{
			min_value = current->content;
			min_index = current_count;
		}
		current = current->next;
		current_count++;
	}
	return (min_index);
}

t_stack	*ft_stack_min(t_stack **stack)
{
	t_stack	*min;
	t_stack	*current;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		return (NULL);
	}
	min = (*stack)->next;
	current = (*stack)->next->next;
	while (current != *stack)
	{
		if (current->content < min->content)
			min = current;
		current = current->next;
	}
	return (min);
}
