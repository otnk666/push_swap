/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:28:19 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/18 11:56:43 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				create_sentinel(t_stack **stack);
void				addstack(t_stack **stack, int count, char *argv[],
						int offset);
void				ft_free_stack(t_stack **stack);
t_stack				*ft_stacknew(int content);
void				ft_stackadd_back(t_stack **stack, t_stack *new);
void				ft_stackadd_front(t_stack **stack, t_stack *new);
void				die(char *cause);

void				swap(t_stack **stack);
void				push(t_stack **stack_to, t_stack **stack_from);
void				rotate(t_stack **stack);
void				re_rotate(t_stack **stack);
int					sa(t_stack **stack_a);
int					sb(t_stack **stack_b);
int					ss(t_stack **stack_a, t_stack **stack_b);
int					pa(t_stack **stack_a, t_stack **stack_b);
int					pb(t_stack **stack_a, t_stack **stack_b);
int					ra(t_stack **stack_a);
int					rb(t_stack **stack_b);
int					rr(t_stack **stack_a, t_stack **stack_b);
int					rra(t_stack **stack_a);
int					rrb(t_stack **stack_b);
int					rrr(t_stack **stack_a, t_stack **stack_b);

void				sort(t_stack **stack_a, t_stack **stack_b);

void				sort_three_a(t_stack **stack_a);
void				sort_three_b(t_stack **stack_b);
void				sort_five(t_stack **stack_a, t_stack **stack_b);
void				quick_sort(t_stack **stack_a, t_stack **stack_b,
						int half_pivot, int min_index);
int					half_partation(t_stack **src, t_stack **dst, int pivot,
						int min_pivot);
int					sort_partation_1(t_stack **src, t_stack **dst, int pivot);
int					sort_partation_2(t_stack **src, t_stack **dst,
						int push_count);
int					ft_is_sorted_ao(t_stack *stack);
int					ft_is_sorted_do(t_stack *stack);
void				ft_addsort(t_stack **stack_a, t_stack **stack_b);

int					ft_stacksize(t_stack *lst);
t_stack				*ft_stack_min(t_stack **stack);
int					ft_stack_min_count(t_stack **stack);
void				ft_push_min(t_stack **stack_a, t_stack **stack_b,
						t_stack *min);

int					ft_findmed(t_stack **stack, int min_pivot);
int					*quickselect_arr(int *array, int left, int right, int k);
int					ft_partition_arr(int *array, int left, int right);
int					*ft_stack_to_array(t_stack *stack, int sizem,
						int min_pivot);

int					ft_check_int(const char *str);
int					ft_check_digit(int argc, char *argv[], int offset);
int					ft_check_arg(int argc, char *argv[]);
int					ft_sting_init(t_stack **stack_a, char *argv);
int					ft_check_dup(t_stack *stack);
int					ft_sorted_size(t_stack *stack);
int					init_stack(t_stack **stack_a, t_stack **stack_b, int argc,
						char *argv[]);
int					init_strarg(t_stack **stack_a, char *argv[]);
void				free_string_args(char **str);

#endif
