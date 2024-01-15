/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:02:49 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/15 21:24:23 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int		i;
	int		med;

	i = 0;
	med = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i-- <= med)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_cost;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_cost)
		{
			cheapest_cost = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		RR(a, b);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		RRR(a, b);
	arrange(a, cheapest, 'a');
	arrange(b, cheapest->target, 'b');
	PB(b, a);
}

t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (tmp);
}

void	push_b(t_stack **a, t_stack **b)
{
	arrange(a, (*b)->target, 'a');
	PA(a, b);
}

void	arrange(t_stack **stack, t_stack *top, char c)
{
	while (*stack != top)
	{
		if (c == 'a')
		{
			if (top->above_median)
				RA(stack);
			else
				RRA(stack);
		}
		else if (c == 'b')
		{
			if (top->above_median)
				RB(stack);
			else
				RRB(stack);
		}
	}
}
