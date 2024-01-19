/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:11:05 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/19 18:52:47 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*curr_b;
	t_stack	*target;
	long	match_index;

	while (a)
	{
		match_index = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->value < a->value && curr_b->value > match_index)
			{
				match_index = curr_b->value;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (match_index == LONG_MIN)
			a->target = get_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	cost_to_a(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (a)
	{
		if (a->above_median && a->target->above_median)
			a->cost = max(a->index, a->target->index);
		else if (!a->above_median && !a->target->above_median)
			a->cost = max(size_a - a->index, size_b - a->target->index);
		else
		{
			if (a->above_median)
				a->cost = a->index + (size_b - a->target->index);
			else
				a->cost = a->target->index + (size_a - a->index);
		}
		a = a->next;
	}
}

void	both_rotate(t_stack **a, t_stack **b, t_stack *top)
{
	while (*a != top && *b != top->target)
	{
		RR(a, b);
		current_index(*a);
		current_index(*b);
	}
}

void	both_rrotate(t_stack **a, t_stack **b, t_stack *top)
{
	while (*a != top && *b != top->target)
	{
		RRR(a, b);
		current_index(*a);
		current_index(*b);
	}
}
