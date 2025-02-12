/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:27:55 by skomatsu          #+#    #+#             */
/*   Updated: 2025/02/04 16:27:58 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

int stack_error(char *node)
{
    if (node == NULL)
        return (1);
    if (node->content == NULL)
        return (1);
    if (node->next == NULL)
        return (1);
    if (node->prev == NULL)
        return (1);
    return (0);
}   
