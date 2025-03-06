/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:56 by skomatsu          #+#    #+#             */
/*   Updated: 2025/03/05 11:09:35 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"



void push_all_to_b(t_stack **stack_a, t_stack **stack_b) {
    while (ft_stacksize(*stack_a) > 0)
        pb(stack_a, stack_b);
}

void push_all_to_a(t_stack **stack_a, t_stack **stack_b) {
    while (ft_stacksize(*stack_b) > 0)
        pa(stack_a, stack_b);
}

void quick_sort(t_stack **stack_a, t_stack **stack_b, int half_pivot, int min_index)
{                               
    // 既にソート済みなら終了
    if(ft_stacksize(*stack_b) == 0 && ft_is_sorted_AO(*stack_a))
        return;
    
    // スタックAが空か要素が1つだけなら終了条件を追加
    if(ft_stacksize(*stack_a) <= 1)
        return;
    

    int pivot_a = half_partation(stack_a, stack_b, half_pivot, min_index);
    int pivot_b = ft_findmed(stack_b, 0);

    int next_min = sort_partation(stack_a, stack_b, pivot_b);

    int size_before = ft_stacksize(*stack_a);

    // In this code, the maximum value is not sorted when half_pivot and min_index are equal
    return(quick_sort(stack_a, stack_b, pivot_a, next_min));
    
    // 無限ループ防止のための明確な終了条件
    if (size_before == ft_stacksize(*stack_a) || ft_is_sorted_AO(*stack_a))
       return;
}

int half_partation(t_stack **src, t_stack **dst, int pivot, int min_pivot) 
{
    int size = ft_stacksize(*src), i = 0;

    if(min_pivot >= pivot)
        return (ft_findmed(src, min_pivot));

    while (i < size)
    {     
        if ((*src)->next->content > min_pivot && (*src)->next->content <= pivot)   
            pb(src, dst);

        else
            ra(src);
        i++;
    }
    
    return (ft_findmed(src, min_pivot));
}

int sort_partation(t_stack **src, t_stack **dst, int pivot)
{
	if(dst == NULL || *dst == NULL || (*dst)->next == *dst)
		return(0);
    static int push_count = 0;
	int size = ft_stacksize(*dst);

	int i = 0;

    if (ft_stacksize(*dst) > 3)
    {
        while (i < size)
	    {
		    if ((*dst)->next->content > pivot)
		    {	
			    pa(src, dst);
			    push_count++;
		    }
		    else
			    rb(dst);
		    i++;
	    }
    }
        if(ft_stacksize(*dst) && ft_stacksize(*dst) <=3)
        {
            while(ft_stacksize(*dst) && ft_stacksize(*dst) <=3)
            {
                sort_three_b(dst);
                ft_addsort(src, dst);
            }
                    if (!push_count && !ft_stacksize(*dst))
                        return (*src)->prev->content;
            while (push_count > 0 && ft_stacksize(*dst) > 0)
            {
                pb(src, dst);
                push_count--;
            }
        }
            
        if(ft_stacksize(*dst) >3)
            return(sort_partation(src, dst, ft_findmed(dst, 0)));
        else if (!ft_stacksize(*dst))
            return((*src)->prev->content);
        return((*src)->prev->content);
    
}


void ft_addsort(t_stack **stack_a, t_stack **stack_b)
{
	while(ft_stacksize(*stack_b) > 0)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}

int	ft_is_sorted_AO(t_stack *stack)
{
	t_stack *current;

	if(!stack || !stack->next)
		return (1);
	current = stack->next;

	while(current -> next != stack)
	{
		if(current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_is_sorted_DO(t_stack *stack)
{
	t_stack *current;

	if(!stack || !stack->next)
		return (1);
	current = stack->next;

	while(current->next != stack)
	{
		if(current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

