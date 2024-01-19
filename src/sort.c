/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:23:59 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/19 18:53:03 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*max;

	max = get_max(*stack_a);
	if (*stack_a == max)
		RA(stack_a);
	else if ((*stack_a)->next == max)
		RRA(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		SA(stack_a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int		size;

	size = ft_lstsize(*a);
	while (size-- > 3)
	{
		current_index(*a);
		while (*a != get_min(*a))
		{
			if (get_min(*a)->above_median)
				RA(a);
			else
				RRA(a);
		}
		PB(b, a);
	}
	sort_three(a);
	PA(a, b);
	PA(a, b);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int		len_a;

	len_a = ft_lstsize(*a);
	PB(b, a);
	PB(b, a);
	while (*a)
	{
		init_a_nodes(*a, *b);
		push_a(a, b);
	}
	current_index(*b);
	max_to_top(b);
	while (*b)
	{
		PA(a, b);
	}
}

void	max_to_top(t_stack **stack)
{
	while ((*stack)->value != get_max(*stack)->value)
	{
		if (get_max(*stack)->above_median)
			RB(stack);
		else
			RRB(stack);
	}
}
