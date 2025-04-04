/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:21:40 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/04 17:22:51 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*tmp;

	if (!stack_from || !*stack_from)
		return ;
	tmp = (*stack_from)->next;
	if (tmp->next == tmp)
	{
		(*stack_from)->next = *stack_from;
		(*stack_from)->prev = *stack_from;
	}
	else
	{
		(*stack_from)->next = tmp->next;
		(*stack_from)->next->prev = *stack_from;
	}
	ft_stackadd_front(stack_to, tmp);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
	return (1);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
	return (1);
}
