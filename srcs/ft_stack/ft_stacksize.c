/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:17:56 by skomatsu          #+#    #+#             */
/*   Updated: 2025/02/06 03:29:38 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_stacksize(t_stack *stack)
{
    int count;
    
    count = 0;
    if (!stack)
        return (0);
    t_stack *current;
    current = stack->next;
    while (current != stack)
    {
        count ++;
        current = current->next;
    }    
    return (count);
}