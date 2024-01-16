/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:23:59 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/16 11:27:11 by melfersi         ###   ########.fr       */
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
	if (len_a-- > 3)
		PB(b, a);
	if (len_a-- > 3)
		PB(b, a);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		// ft_puts("here1");
		init_a_nodes(*a, *b);
		push_a(a, b);
	}
	sort_three(a);
	while (*b)
	{
		// ft_puts("here2");
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





















// void	sort_four(t_list **stack_a, t_list **stack_b)
// {
// 	int		min;
// 	int		max;
// 	int		i;

// 	min = get_min(*stack_a);
// 	max = get_max(*stack_a);
// 	i = 0;
// 	while (i < 2)
// 	{
// 		if (*(int *)(*stack_a)->content == min || *(int *)(*stack_a)->content == max)
// 		{
// 			PB(stack_b, stack_a);
// 			i++;
// 		}
// 		else
// 			RA(stack_a);
// 	}
// 	if (!is_sorted(*stack_a) && !is_sorted(*stack_b))
// 		SS(stack_a, stack_b);
// 	if (!is_sorted(*stack_b))
// 		SB(stack_b);
// 	if (!is_sorted(*stack_a))
// 		SA(stack_a);
// 	PA(stack_b, stack_a);
// 	PA(stack_b, stack_a);
// 	RA(stack_a);
// }

// void	sort_five(t_list **stack_a, t_list **stack_b)
// {
// 	int		min;
// 	int		max;
// 	int		i;

// 	min = get_min(*stack_a);
// 	max = get_max(*stack_a);
// 	i = 0;
// 	while (i < 2)
// 	{
// 		if (*(int *)(*stack_a)->content == min || *(int *)(*stack_a)->content == max)
// 		{
// 			PB(stack_b, stack_a);
// 			i++;
// 		}
// 		else
// 			RA(stack_a);
// 	}
// 	sort_three(stack_a);
// 	if (!is_sorted(*stack_b))
// 		SB(stack_b);
// 	PA(stack_b, stack_a);
// 	PA(stack_b, stack_a);
// 	RA(stack_a);
// }

