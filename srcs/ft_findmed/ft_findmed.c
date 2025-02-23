/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findmed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:52:56 by skomatsu          #+#    #+#             */
/*   Updated: 2025/02/19 01:04:42 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "../libft/libft.h"

int ft_partiton_arr(int *array, int left, int right)
{
    int pivot;
    int i;
    int j;
    int tmp;

    pivot = array[right];
    i = left - 1;
    j = left;
    while(j < right)
    {
        if(array[j] < pivot)
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
    return(i + 1);
}

int ft_quickselect_arr(int *array, int left, int right, int k)
{
    int pivot;
    pivot = ft_partiton_arr(array, left, right);
    if(pivot == k)
        return(array[pivot]);
    else if (pivot < k)
        return(ft_quickselect_arr(array, pivot + 1, right, k));
    else
        return(ft_quickselect_arr(array, left, pivot - 1, k));
}


int *ft_stack_to_array(t_stack *stack, int size)
{
    if(size <= 1)
        return(NULL);
    int i;
    int *array;
    array = (int *)malloc(sizeof(int) * (size + 1));
    if (!array)
        return(NULL);
    
    t_stack *current;

    i = 0;
    current = stack->next;
    while(current != stack)
    {
        array[i] = current->content;
        current = current->next;
        i++;
    }
    return(array);
}


int ft_findmed(t_stack **stack)
{
    int size;
    int *array;
    int medium;


    size = ft_stacksize(*stack);
    if(size == 0)
        return(0);
    else if(size == 1)
        return((*stack)->next->content);
    array = ft_stack_to_array(*stack, size);
    medium = ft_quickselect_arr(array, 0, size - 1, size/2);
    free(array);

    return(medium);

}