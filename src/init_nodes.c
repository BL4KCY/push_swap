/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:11:05 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/19 10:48:41 by melfersi         ###   ########.fr       */
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

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*curr_a;
	t_stack	*target;
	long	match_index;

	while (b)
	{
		match_index = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->value > b->value && curr_a->value < match_index)
			{
				match_index = curr_a->value;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (match_index == LONG_MAX)
			b->target = get_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	cost_to_a(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (a)
	{
		a->cost = a->index;
		if (!a->above_median)
			a->cost = size_a - a->index;
		if (a->target->above_median)
			a->cost += a->target->index;
		else
			a->cost += size_b - a->target->index;
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
