/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:27:24 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/27 20:39:10 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_command(t_stack **stack_a, t_stack **stack_b, char *line)
{
    if (ft_strncmp(line, "sa", 2) == 0 && line[2] == '\0')
        sa(stack_a);
    else if (ft_strncmp(line, "sb", 2) == 0 && line[2] == '\0')
        sb(stack_b);
    else if (ft_strncmp(line, "ss", 2) == 0 && line[2] == '\0')
        ss(stack_a, stack_b);
    else if (ft_strncmp(line, "pa", 2) == 0 && line[2] == '\0')
        pa(stack_a, stack_b);
    else if (ft_strncmp(line, "pb", 2) == 0 && line[2] == '\0')
        pb(stack_a, stack_b);
    else if (ft_strncmp(line, "ra", 2) == 0 && line[2] == '\0')
        ra(stack_a);
    else if (ft_strncmp(line, "rb", 2) == 0 && line[2] == '\0')
        rb(stack_b);
    else if (ft_strncmp(line, "rr", 2) == 0 && line[2] == '\0')
        rr(stack_a, stack_b);
    else if (ft_strncmp(line, "rra", 3) == 0 && line[3] == '\0')
        rra(stack_a);
    else if (ft_strncmp(line, "rrb", 3) == 0 && line[3] == '\0')
        rrb(stack_b);
    else if (ft_strncmp(line, "rrr", 3) == 0 && line[3] == '\0')
        rrr(stack_a, stack_b);
    else
        ft_printf("Error\n");
}

void sa(t_stack **stack_a)
{
    swap(stack_a);
    ft_printf("sa\n");
}

void sb(t_stack **stack_b)
{
    swap(stack_b);
    ft_printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    ft_printf("ss\n");
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_printf("pa\n");
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    ft_printf("pb\n");
}

void ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_printf("ra\n");
}

void rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_printf("rb\n");
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_printf("rr\n");
}

void rra(t_stack **stack_a)
{
    re_rotate(stack_a);
    ft_printf("rra\n");
}

void rrb(t_stack **stack_b)
{
    re_rotate(stack_b);
    ft_printf("rrb\n");
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    re_rotate(stack_a);
    re_rotate(stack_b);
    ft_printf("rrr\n");
}

void swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;

    if (!stack || !*stack || !((*stack)->next))
        return;    
    first = (*stack)->next;
    second = first->next;
    first->next = second->next;
    second->next->prev = first;
    second->next = first;
    second->prev = *stack;
    first->prev = second;
    (*stack)->next = second;
    return;
}

void push(t_stack **stack_to, t_stack **stack_from)
{
    t_stack *tmp;

    if (!stack_from || !*stack_from)
        return;

    tmp = (*stack_from)->next;
    if (tmp->next == tmp)
    {
        (*stack_from)->next = *stack_from;
        (*stack_from)->prev = *stack_from;
    }
    else
    {
       (*stack_from)->next = tmp->next;
       (*stack_from)->next->prev = *stack_from;
    }
        ft_stackadd_front(stack_to, tmp);
}

void rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (!stack || !*stack || !((*stack)->next))
        return;

    first = (*stack)->next;
    last = (*stack)->prev;

    (*stack)->next = first->next;
    first->next->prev = *stack;


    first->next = *stack;
    first->prev = last;
    last->next = first;
    (*stack)->prev = first;
}

void re_rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if(!stack || !*stack || !((*stack)->next))
        return;
        
    first = (*stack)->next;
    last = (*stack)->prev;

    (*stack)->prev = last->prev;
    last->prev->next = *stack;

    (*stack)->next = last;
    last->next = first;
    last->prev = *stack;
    first->prev = last;
}
