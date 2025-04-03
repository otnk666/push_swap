/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:27:24 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/03 11:11:48 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
