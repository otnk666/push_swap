/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:56 by skomatsu          #+#    #+#             */
/*   Updated: 2025/02/04 18:11:09 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	push_all_to_b(t_list **stack_a, t_list **stack_b)
{
	while(ft_lstsize(*stack_a) > 0)
		ft_command(stack_a, stack_b, "pb");
}

void	push_all_to_a(t_list **stack_a, t_list **stack_b)
{
	while(ft_lstsize(*stack_b) > 0)
		ft_command(stack_a, stack_b, "pa");
}

int quick_sort(t_list **stack_a, t_list **stack_b)
{
	t_list *current;
	int pivot;
	int size;
	int i;

	current = (*stack_a)->next;
	pivot = current->content;
	size = ft_lstsize(stack_a);

	while(i < size)
	{
		if (current->content < pivot)
			ft_command(stack_a, stack_b, "pb");
		else
			ft_command(stack_a, stack_b, "ra");
		i++;
	}
	quick_sort(stack_a,stack_b);
	push_all_to_a(stack_a, stack_b);
}

