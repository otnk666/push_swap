/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:01:09 by skomatsu          #+#    #+#             */
/*   Updated: 2025/02/06 03:02:42 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (*stack)
	{
		last = (*stack)->prev;
		last->next = new;
		new->prev = last;
		new->next = *stack;
		(*stack)->prev = new;
	}
	else
	{
		*stack = new;
		new->next = new;
		new->prev = new;
	}
}
