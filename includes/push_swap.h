/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:28:19 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/27 20:37:21 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"

#include <unistd.h>
#include <stdlib.h>


typedef struct s_stack
{
    int content;
    struct s_stack *next;
    struct s_stack *prev;
}       t_stack;


void        ft_command(t_stack **stack_a, t_stack **stack_b, char *line);
void        create_sentinel(t_stack **stack);
void        addstack(t_stack **stack, int argc, char *argv[]);
void        ft_free_stack(t_stack **stack);
t_stack     *ft_stacknew(int content);
void        ft_stackadd_back(t_stack **stack, t_stack *new);
void        ft_stackadd_front(t_stack **stack, t_stack *new);
void        die(char *cause);



void    swap(t_stack **stack);
void    push(t_stack **stack_to, t_stack **stack_from);
void    rotate(t_stack **stack);
void    re_rotate(t_stack **stack);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a, t_stack **stack_b);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);

void    sort(t_stack **stack_a, t_stack **stack_b);
void    sort_three_a(t_stack **stack_a);
void    sort_three_b(t_stack **stack_b);
void    sort_five(t_stack **stack_a, t_stack **stack_b);
void    quick_sort(t_stack **stack_a, t_stack **stack_b, int half_pivot, int min_index);
int     half_partation(t_stack **src, t_stack **dst, int pivot, int min_pivot);
int     sort_partation(t_stack **src, t_stack **dst, int pivot);

int     ft_is_sorted_AO(t_stack *stack);
int     ft_is_sorted_DO(t_stack *stack);
void    ft_addsort(t_stack **stack_a, t_stack **stack_b);

int     ft_stacksize(t_stack *lst);
t_stack *ft_stack_min(t_stack **stack);
int     ft_stack_min_count(t_stack **stack);
void    ft_push_min(t_stack **stack_a, t_stack **stack_b, t_stack *min);

int     stack_error(t_stack *node);
int     ft_findmed(t_stack **stack, int min_pivot);
int     *quickselect_arr(int *array, int left, int right, int k);
int     ft_partition_arr(int *array, int left, int right);
int     *ft_stack_to_array(t_stack *stack, int sizem, int min_pivot);

int    ft_check_int(const char *str);
int    ft_check_digit(int argc, char *argv[]);
int    ft_check_arg(int argc, char *argv[]);
int    ft_check_dup(t_stack *stack);
int    ft_sorted_size(t_stack *stack);
int    init_stack(t_stack **stack_a, t_stack **stack_b, int argc, char *argv[]);


int    ft_rotate_dir(t_stack *stack, int target);
void   ft_optimal_rotate(t_stack **stack, int target, char stack_id);
int    ft_find_greater(t_stack *stack, int target);

#endif
