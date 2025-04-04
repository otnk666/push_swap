/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:24:54 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/04 17:25:21 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	first = (*stack)->next;
	last = (*stack)->prev;
	(*stack)->next = first->next;
	first->next->prev = *stack;
	first->next = *stack;
	first->prev = last;
	last->next = first;
	(*stack)->prev = first;
}

int	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	return (1);
}
