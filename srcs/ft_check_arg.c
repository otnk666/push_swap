/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:18:12 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/27 20:38:27 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_int(const char *str)
{
    long num;

    num = ft_long_atoi(str);
    return (INT_MIN <= num && num <= INT_MAX);
}

int ft_check_digit(int argc, char *argv[])
{
    size_t i;
    size_t j;

    i = 1;
    while (i < (size_t)argc)
    {
        if (argv[i][0] != '-' && !(ft_isdigit(argv[i][0])))
            return (0);
        j = 1;
        while (argv[i][j] != '\0')
        {
            if (!(ft_isdigit(argv[i][j++])))
                return (0);
        }
        if (!ft_check_int(argv[i]))
            return (0);
        i++;
    }
    return (1);
}

int ft_check_arg(int argc, char *argv[])
{
    if (argc <= 0)
        return (0);
    if (argc == 1)
        exit (0);
    if (!ft_check_digit(argc, argv))
        return (0);
    return (1);
}

int ft_check_dup(t_stack *stack)
{
    t_stack *current;
    t_stack *check;

    current = stack->next;
    while (current != stack)
    {
        check = current->next;
        while (check != stack)
        {
            if (current->content == check->content)
                return (0);
            check = check->next;
        }
        current = current->next;
    }
    return (1);
}

