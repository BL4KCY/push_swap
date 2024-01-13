/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:55:17 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/13 15:41:35 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	exist(t_list *stack, int value)
{
	while (stack)
	{
		if (*(int *)stack->content == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

int	get_min(t_list *stack)
{
	int		min;
	t_list	*tmp;

	tmp = stack;
	min = *(int *)tmp->content;
	while (tmp)
	{
		if (*(int *)tmp->content < min)
			min = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_list *stack)
{
	int		max;
	t_list	*tmp;

	tmp = stack;
	max = *(int *)tmp->content;
	while (tmp)
	{
		if (*(int *)tmp->content > max)
			max = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (max);
}
