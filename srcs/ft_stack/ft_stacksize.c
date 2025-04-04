/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:17:56 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/04 17:05:02 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int		count;
	t_stack	*current;

	count = 0;
	if (!stack)
		return (0);
	current = stack->next;
	while (current != stack)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	ft_nosorted_size(t_stack *stack, int last_sorted)
{
	int		count;
	t_stack	*current;

	count = 0;
	if (!stack)
		return (0);
	current = stack->next;
	while (current != stack)
	{
		if (current->content > last_sorted)
			count++;
		current = current->next;
	}
	return (count);
}
