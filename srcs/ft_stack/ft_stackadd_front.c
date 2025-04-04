/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:05:56 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/04 17:05:35 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	t_stack	*first;

	if (!stack || !new)
		return ;
	if (*stack)
	{
		first = (*stack)->next;
		first->prev = new;
		new->next = first;
		new->prev = *stack;
		(*stack)->next = new;
	}
	else
	{
		*stack = new;
		new->next = new;
		new->prev = new;
	}
}
