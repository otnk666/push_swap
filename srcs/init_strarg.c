/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:50:31 by skomatsu          #+#    #+#             */
/*   Updated: 2025/04/04 17:52:12 by skomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_string_args(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	init_strarg(t_stack **stack_a, char *argv[])
{
	char	**split;
	int		split_count;

	split_count = 0;
	split = ft_split(argv[1], ' ');
	if (!split)
		die ("Error");
	while (split[split_count])
		split_count++;
	if (split_count == 0)
	{
		free_string_args(split);
		return (0);
	}
	if (!ft_check_digit(split_count, split, 0))
	{
		free_string_args(split);
		return (0);
	}
	addstack(stack_a, split_count, split, 0);
	free_string_args(split);
	return (1);
}
