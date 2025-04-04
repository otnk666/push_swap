/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:56 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/04 17:06:52 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stack **stack_a, t_stack **stack_b, int half_pivot,
		int min_index)
{
	int	pivot_a;
	int	pivot_b;
	int	next_min;
	int	size_before;

	if (ft_stacksize(*stack_b) == 0 && ft_is_sorted_ao(*stack_a))
		return ;
	if (ft_stacksize(*stack_a) <= 1)
		return ;
	pivot_a = half_partation(stack_a, stack_b, half_pivot, min_index);
	pivot_b = 0;
	next_min = min_index;
	size_before = ft_stacksize(*stack_a);
	if (ft_stacksize(*stack_b) > 0)
	{
		pivot_b = ft_findmed(stack_b, 0);
		next_min = sort_partation_1(stack_a, stack_b, pivot_b);
	}
	if (size_before != ft_stacksize(*stack_a) && !ft_is_sorted_ao(*stack_a))
		quick_sort(stack_a, stack_b, pivot_a, next_min);
}

int	half_partation(t_stack **src, t_stack **dst, int pivot, int min_pivot)
{
	int			size;
	int			i;
	static int	push_count;
	int			rotate_count;
	int			unsorted;

	rotate_count = 0;
	size = ft_stacksize(*src);
	i = 0;
	unsorted = size - push_count;
	if (min_pivot >= pivot)
		return (ft_findmed(src, min_pivot));
	while (i < unsorted)
	{
		if ((*src)->next->content > min_pivot && (*src)->next->content <= pivot)
			push_count += pb(src, dst);
		else
			rotate_count += ra(src);
		i++;
	}
	while (rotate_count > 0)
		rotate_count -= rra(src);
	return (ft_findmed(src, pivot));
}

int	sort_partation_1(t_stack **src, t_stack **dst, int pivot)
{
	int	push_count;
	int	size;
	int	i;

	if (dst == NULL || *dst == NULL || (*dst)->next == *dst)
		return (0);
	push_count = 0;
	size = ft_stacksize(*dst);
	i = 0;
	while (i < size && size > 3)
	{
		if ((*dst)->next->content > pivot)
			push_count += pa(src, dst);
		else
			rb(dst);
		i++;
	}
	return (sort_partation_2(src, dst, push_count));
}

int	sort_partation_2(t_stack **src, t_stack **dst, int push_count)
{
	if (ft_stacksize(*dst) > 3)
		sort_partation_1(src, dst, ft_findmed(dst, 0));
	if (ft_stacksize(*dst) && ft_stacksize(*dst) <= 3)
	{
		sort_three_b(dst);
		ft_addsort(src, dst);
	}
	while (push_count > 0)
		push_count -= pb(src, dst);
	if (ft_stacksize(*dst))
		sort_partation_1(src, dst, ft_findmed(dst, 0));
	return ((*src)->prev->content);
}

void	ft_addsort(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stacksize(*stack_b) > 0)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}
