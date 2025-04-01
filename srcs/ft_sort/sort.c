/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:10:03 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/01 19:24:11 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->next->content;
	b = (*stack_a)->next->next->content;
	c = (*stack_a)->prev->content;
	if (ft_stacksize(*stack_a) == 2 && a > b)
		sa(stack_a);
	else if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

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

void	sort_three_b(t_stack **stack_b)
{
	int	size;
	int	a;
	int	b;
	int	c;

	a = (*stack_b)->next->content;
	b = (*stack_b)->next->next->content;
	c = (*stack_b)->prev->content;
	size = ft_stacksize(*stack_b);
	if (size <= 1 || (size == 2 && a < b))
		return ;
	if (ft_stacksize(*stack_b) == 2 && a > b)
		sb(stack_b);
	if (a > b && b < c && a < c)
		sb(stack_b);
	else if (a > b && b > c && a > c)
	{
		sb(stack_b);
		rrb(stack_b);
	}
	else if (a > b && b < c && a > c)
		rb(stack_b);
	else if (a < b && b > c && a < c)
	{
		sb(stack_b);
		rb(stack_b);
	}
	else if (a < b && b > c && a > c)
		rrb(stack_b);
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

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pivot;

	size = ft_stacksize(*stack_a);
	pivot = ft_findmed(stack_a, 0);
	
	if (size == 1)
		return;
	else if (size <= 3)
		sort_three_a(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		quick_sort(stack_a, stack_b, pivot, 0);
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
