/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:23:59 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/13 15:50:54 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int		a;
	int		b;
	int		c;

	a = *(int *)(*stack_a)->content;
	b = *(int *)(*stack_a)->next->content;
	c = *(int *)(*stack_a)->next->next->content;
	if (a > b && b < c && a < c)
		SA(stack_a);
	else if (a > b && b > c && a > c)
	{
		SA(stack_a);
		RRA(stack_a);
	}
	else if (a > b && b < c && a > c)
	{
		RA(stack_a);
	}
	else if (a < b && b > c && a < c)
	{
		RRA(stack_a);
		SA(stack_a);
	}
	else if (a < b && b > c && a > c)
		RRA(stack_a);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		max;
	int		i;

	min = get_min(*stack_a);
	max = get_max(*stack_a);
	i = 0;
	while (i < 2)
	{
		if (*(int *)(*stack_a)->content == min || *(int *)(*stack_a)->content == max)
		{
			PB(stack_b, stack_a);
			i++;
		}
		else
			RA(stack_a);
	}
	if (!is_sorted(*stack_a) && !is_sorted(*stack_b))
		SS(stack_a, stack_b);
	if (!is_sorted(*stack_b))
		SB(stack_b);
	if (!is_sorted(*stack_a))
		SA(stack_a);
	PA(stack_b, stack_a);
	PA(stack_b, stack_a);
	RA(stack_a);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		max;
	int		i;

	min = get_min(*stack_a);
	max = get_max(*stack_a);
	i = 0;
	while (i < 2)
	{
		if (*(int *)(*stack_a)->content == min || *(int *)(*stack_a)->content == max)
		{
			PB(stack_b, stack_a);
			i++;
		}
		else
			RA(stack_a);
	}
	sort_three(stack_a);
	if (!is_sorted(*stack_b))
		SB(stack_b);
	PA(stack_b, stack_a);
	PA(stack_b, stack_a);
	RA(stack_a);
}

