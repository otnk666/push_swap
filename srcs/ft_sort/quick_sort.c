/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:25:56 by skomatsu          #+#    #+#             */
/*   Updated: 2025/02/27 02:55:30 by skomatsu         ###   ########.fr       */
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
    
    int first_pivot = ft_findmed(stack_a);
    int pivot_b = half_partation(stack_a, stack_b, half_pivot, min_index);
    
    // pivotが適切に見つからなかった場合の処理
    if (pivot_b == 0 && ft_stacksize(*stack_b) == 0) 
	{
        // 別の方法でパーティション分けを試みる
        pb(stack_a, stack_b);
        return;
    }
    
    int pivot_a = ft_findmed(stack_a);
    sort_partation(stack_a, stack_b, pivot_b);

    int size_before = ft_stacksize(*stack_a);
    quick_sort(stack_a, stack_b, pivot_a, first_pivot);
    
    // 無限ループ防止のための明確な終了条件
    if (size_before == ft_stacksize(*stack_a) || ft_is_sorted_AO(*stack_a))
       return;
}

int half_partation(t_stack **src, t_stack **dst, int pivot, int min_pivot) 
{
    int size = ft_stacksize(*src), i = 0;

    while (i < size)
    {
        if ((*src)->next->content > min_pivot && (*src)->next->content <= pivot)   
            pb(src, dst);
        else
            ra(src);
        i++;
    }
    
    // スタックBが空の場合の改善された処理
    if (ft_stacksize(*dst) == 0) {
        // srcのサイズをチェック
        if (ft_stacksize(*src) <= 1)
            return (0);
            
        // srcの要素を分析して適切なピボットを選択
        t_stack *current = (*src)->next;
        int min = current->content;
        int max = current->content;
        
        // 最小値と最大値を見つける
        while (current->next != *src) {
            if (current->content < min)
                min = current->content;
            if (current->content > max)
                max = current->content;
            current = current->next;
        }
        
        // 中間値を新しいピボットとして返す
        return ((min + max) / 2);
    }
    return (ft_findmed(dst));
}

void sort_partation(t_stack **src, t_stack **dst, int pivot)
{
	if(dst == NULL || *dst == NULL || (*dst)->next == *dst)
		return;

	int size = ft_stacksize(*dst);

	
	int i = 0;
	int push_count = 0;

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

    if(ft_stacksize(*dst) <= 3)
    {
        sort_three_b(dst);
        ft_addsort(src, dst);
        while(push_count-- > 0)
            pb(src, dst);
        return; // 終了条件を追加
    }
    
    // 無限再帰を防ぐための追加チェック
    int new_pivot = ft_findmed(dst);
    if(new_pivot == pivot || ft_stacksize(*dst) == 0)
        return;
        
    // サイズが変わらない場合の対策
    int size_before = ft_stacksize(*dst);
    sort_partation(src, dst, new_pivot);
    if (size_before == ft_stacksize(*dst))
        return;
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
