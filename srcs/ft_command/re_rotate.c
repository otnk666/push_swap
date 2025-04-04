/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:25:39 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/04 17:43:22 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	first = (*stack)->next;
	last = (*stack)->prev;
	(*stack)->prev = last->prev;
	last->prev->next = *stack;
	(*stack)->next = last;
	last->next = first;
	last->prev = *stack;
	first->prev = last;
}

int	rra(t_stack **stack_a)
{
	re_rotate(stack_a);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **stack_b)
{
	re_rotate(stack_b);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	re_rotate(stack_a);
	re_rotate(stack_b);
	ft_printf("rrr\n");
	return (1);
}
