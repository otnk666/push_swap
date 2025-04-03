/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:36:27 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/02 16:10:44 by skomatsu         ###   ########.fr       */
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

void	addstack(t_stack **stack, int count, char *argv[], int offset)
{
	int		i;
	int		temp;
	t_stack	*new_node;

	i = offset;
	while (i < count)
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
	if (argc == 2)
	{
		if (!ft_string_init(stack_a, argv))
			return (0);	
	}
	else 
	{
		addstack(stack_a, argc, argv, 1);
	}
	if (!ft_check_dup(*stack_a))
		return (0);
	return (1);
}

int	ft_string_init(t_stack **stack_a, char *argv[])
{
	char **split;
	int	split_count;

	split_count = 0;
	split = ft_split(argv[1], ' ');
	if (!split)
		die ("Error");
	while (split[split_count])
		split_count++;
	if (split_count == 0)
	{
		free_string_args(split);
		return (0);
	}
	if (!ft_check_digit(split_count, split, 0))
	{
		free_string_args(split);
		return (0);
	}
	addstack(stack_a, split_count, split, 0);
	free_string_args(split);
	return (1);
	
}

void free_string_args(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}