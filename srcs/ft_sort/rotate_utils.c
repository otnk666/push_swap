/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 08:13:32 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/08 08:39:49 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_dir(t_stack *stack, int target)
{
	t_stack	*current;
	int		count;
	int		size;

	count = 0;
	current = stack->next;
	size = ft_stacksize(stack);
	while (current != stack)
	{
		if (current->content == target)
			break ;
		count++;
		current = current->next;
	}
	if (count <= size / 2)
		return (1);
	return (-1);
}

void	ft_optimal_rotate(t_stack **stack, int target, char stack_id)
{
	int	dir;

	dir = ft_rotate_dir(*stack, target);
	if ((*stack)->next->content == target)
		return ;
	if (dir == 1)
	{
		if (stack_id == 'a')
			ra(stack);
		else
			rb(stack);
	}
	else
	{
		if (stack_id == 'a')
			rra(stack);
		else
			rrb(stack);
	}
}

int	ft_find_greater(t_stack *stack, int target)
{
	t_stack *current;
	current = stack->next;

	while (current != stack)
	{
		if (current->content > target)
			return (current->content);
		current = current->next;
	}
	return (0);
}