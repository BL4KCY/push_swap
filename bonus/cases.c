/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:16:45 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/18 12:33:41 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		push_case(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(operation, "pa\n", ft_strlen(operation)) == 0)
	{
		PA(stack_a, stack_b);
		return (true);
	}
	else if (ft_strncmp(operation, "pb\n", ft_strlen(operation)) == 0)
	{
		PB(stack_b, stack_a);
		return (true);
	}
	return (false);
}

int		swap_case(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(operation, "sa\n", ft_strlen(operation)) == 0)
	{
		SA(stack_a);
		return (true);
	}
	else if (ft_strncmp(operation, "sb\n", ft_strlen(operation)) == 0)
	{
		SB(stack_b);
		return (true);
	}
	else if (ft_strncmp(operation, "ss\n", ft_strlen(operation)) == 0)
	{
		SS(stack_a, stack_b);
		return (true);
	}
	return (false);
}

int		rotate_case(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(operation, "ra\n", ft_strlen(operation)) == 0)
	{
		RA(stack_a);
		return (true);
	}
	else if (ft_strncmp(operation, "rb\n", ft_strlen(operation)) == 0)
	{
		RB(stack_b);
		return (true);
	}
	else if (ft_strncmp(operation, "rr\n", ft_strlen(operation)) == 0)
	{
		RR(stack_a, stack_b);
		return (true);
	}
	return (false);
}
int		rev_rotate_case(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(operation, "rra\n", ft_strlen(operation)) == 0)
	{
		RRA(stack_a);
		return (true);
	}
	else if (ft_strncmp(operation, "rrb\n", ft_strlen(operation)) == 0)
	{
		RRB(stack_b);
		return (true);
	}
	else if (ft_strncmp(operation, "rrr\n", ft_strlen(operation)) == 0)
	{
		RRR(stack_a, stack_b);
		return (true);
	}
	return (false);
}
