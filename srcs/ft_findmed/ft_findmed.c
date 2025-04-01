/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findmed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:52:56 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/01 20:14:12 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_partition_arr(int *array, int left, int right)
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	pivot = array[right];
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		j++;
	}
	tmp = array[i + 1];
	array[i + 1] = array[right];
	array[right] = tmp;
	return (i + 1);
}

int	ft_quickselect_arr(int *array, int left, int right, int k)
{
	int	pivot;

	pivot = ft_partition_arr(array, left, right);
	if (pivot == k)
		return (array[pivot]);
	else if (pivot < k)
		return (ft_quickselect_arr(array, pivot + 1, right, k));
	else
		return (ft_quickselect_arr(array, left, pivot - 1, k));
}

int	*ft_stack_to_array(t_stack *stack, int size, int min_pivot)
{
	int	i;
	int	*array;

	if (size <= 0 || !stack || !stack->next)
		return (NULL);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	t_stack *current = stack->next;
	i = 0;
	while (current != stack)
	{
		if (current->content > min_pivot)
		{
			array[i] = current->content;
			i++;
		}
		current = current->next;
	}
	return (array);
}

int	ft_findmed(t_stack **stack, int min_pivot)
{
	int	size;
	int	median;

	if (!*stack || !(*stack)->next)
		return (0);
	size = 0;
	t_stack *current = (*stack)->next;
	while (current != *stack)
	{
		if (current->content > min_pivot)
			size++;
		current = current->next;
	}
	if (size == 0)
		return (min_pivot);
	int *array = ft_stack_to_array(*stack, size, min_pivot);
	if (!array)
		return (0);
	median = ft_quickselect_arr(array, 0, size - 1, size / 2);
	free(array);
	return (median);
}
