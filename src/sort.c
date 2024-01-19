/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:23:59 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/19 10:51:36 by melfersi         ###   ########.fr       */
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

void	sort_stacks(t_stack **a, t_stack **b)
{
	int		len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		PB(b, a);
	if (len_a-- > 3 && !is_sorted(*a))
		PB(b, a);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		init_a_nodes(*a, *b);
		push_a(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b_nodes(*a, *b);
		push_b(a, b);
	}
	current_index(*a);
	min_to_top(a);
}

void	min_to_top(t_stack **stack)
{
	while ((*stack)->value != get_min(*stack)->value)
	{
		if (get_min(*stack)->above_median)
			RA(stack);
		else
			RRA(stack);
	}
}

void	push_b(t_stack **a, t_stack **b)
{
	arrange(a, (*b)->target, 'a');
	PA(a, b);
}
