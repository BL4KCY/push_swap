/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:02:49 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/19 10:51:24 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int		i;
	int		med;

	if (!stack)
		return ;
	i = 0;
	med = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= med)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_cost;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_cost)
		{
			cheapest_cost = stack->cost;
			cheapest_node = stack;
		}
		else
			stack->cheapest = false;
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		both_rotate(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		both_rrotate(a, b, cheapest);
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
