/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:36:27 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/30 11:45:17 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_sentinel(t_stack **stack)
{
	t_stack	*sentinel;

	sentinel = ft_stacknew(0);
	if (!sentinel)
		return ;
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
	*stack = sentinel;
}

void	addstack(t_stack **stack, int argc, char *argv[])
{
	int		i;
	int		temp;
	t_stack	*new_node;

	i = 1;
	while (i < argc)
	{
		temp = ft_atoi(argv[i]);
		new_node = ft_stacknew(temp);
		if (!new_node)
			return ;
		ft_stackadd_back(stack, new_node);
		i++;
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*sentinel;
	t_stack	*next;

	sentinel = *stack;
	current = (*stack)->next;
	while (current != sentinel)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(sentinel);
	*stack = NULL;
}

int	init_stack(t_stack **stack_a, t_stack **stack_b, int argc, char *argv[])
{
	create_sentinel(stack_a);
	create_sentinel(stack_b);
	if (!stack_a || !stack_b)
		return (0);
	addstack(stack_a, argc, argv);
	if (!ft_check_dup(*stack_a))
		return (0);
	return (1);
}