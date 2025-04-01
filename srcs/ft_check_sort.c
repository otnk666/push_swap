/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:42:44 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/01 20:12:04 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_size(t_stack *stack)
{
	int			sorted_count;
	t_stack		*current;
	int			total_size;
	static int	first_call;

	first_call = 0;
	sorted_count = 0;
	current = stack->prev;
	total_size = ft_stacksize(stack);
	if (first_call == 0)
	{
		first_call = 1;
		return (0);
	}
	while (current != stack)
	{
		if (current->content > current->prev->content)
			sorted_count++;
		else if (sorted_count && current->content < current->prev->content)
		{
			sorted_count++;
			break ;
		}
		else
			break ;
		current = current->prev;
	}
	if (sorted_count == total_size)
		return (total_size);
	return (sorted_count);
}

int	ft_is_sorted_AO(t_stack *stack)
{
	t_stack	*current;

	if (!stack || !stack->next)
		return (1);
	current = stack->next;
	while (current->next != stack)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_is_sorted_DO(t_stack *stack)
{
	t_stack	*current;

	if (!stack || !stack->next)
		return (1);
	current = stack->next;
	while (current->next != stack)
	{
		if (current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
