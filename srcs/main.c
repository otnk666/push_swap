/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:27:03 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/06 15:14:35 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "../libft/libft.h"

int main(int argc, char *argv[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (!check_arg(argc, argv))
    {
        ft_putendl_fd("Error", STDERR_FILENO);
        exit (1);
    }
    if(init_stack(&stack_a, &stack_b, argc, argv))
    {
        ft_putendl_fd("Error", STDERR_FILENO);
        exit (1);
    }
    sort(&stack_a, &stack_b);
    ft_free_stack(&stack_a);
    ft_free_stack(&stack_b);
    return (0);
}
