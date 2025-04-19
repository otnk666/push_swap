/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:10:03 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/19 18:32:37 by skomatsu         ###   ########.fr       */
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

void	sort_three_b(t_stack **stack_b)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_b)->next->content;
	b = (*stack_b)->next->next->content;
	c = (*stack_b)->prev->content;
	if (ft_stacksize(*stack_b) <= 1 || (ft_stacksize(*stack_b) == 2 && a < b))
		return ;
	if (ft_stacksize(*stack_b) == 2 && a > b)
		sb(stack_b);
	if (a > b && b < c && a < c)
		sb(stack_b);
	else if (a > b && b > c && a > c)
		(sb(stack_b), rrb(stack_b));
	else if (a > b && b < c && a > c)
		rb(stack_b);
	else if (a < b && b > c && a < c)
		(sb(stack_b), rb(stack_b));
	else if (a < b && b > c && a > c)
		rrb(stack_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pivot;

	size = ft_stacksize(*stack_a);
	pivot = ft_findmed(stack_a, INT_MIN);
	if (size == 1)
		return ;
	else if (size <= 3)
		sort_three_a(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		quick_sort(stack_a, stack_b, pivot, INT_MIN);
}
