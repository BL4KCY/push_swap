/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:38:58 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/17 13:10:08 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(int content)
{
	ft_putnbr_fd(content, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}


int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	parse_args(ac, av, &stack_a);
	if (!is_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) == 2)
			SA(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	// ft_puts("stack A");
	// ft_lstiter(stack_a, print);
	ft_lstclear(&stack_a);
	return (0);
}

