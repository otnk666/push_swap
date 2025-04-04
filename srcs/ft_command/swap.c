/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:23:39 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/04 17:24:07 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	first = (*stack)->next;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->next = first;
	second->prev = *stack;
	first->prev = second;
	(*stack)->next = second;
	return ;
}

int	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
	return (1);
}

int	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	return (1);
}
