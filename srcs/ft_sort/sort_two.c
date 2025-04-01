/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:10:06 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/01 19:15:46 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_two(t_stack **stack)
{
    int a;
    int b;

    a = (*stack)->next->content;
    b = (*stack)->prev->content;
    if(a > b)
        rotate(stack);
}