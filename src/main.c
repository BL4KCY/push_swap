/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:38:58 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/13 22:15:17 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(void *content)
{
	ft_putnbr_fd(*(int *)content, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}


int main(int ac, char **av)
{
	push_swap(ac, av);
	return (0);
}

void	push_swap(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return ;
	parse_args(ac, av, &stack_a);
	if (is_sorted(stack_a))
	{
		ft_lstclear(&stack_a, free);
		return ;
	}
	if (ft_lstsize(stack_a) == 2)
		SA(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_three(&stack_a);
	else if (ft_lstsize(stack_a) == 4)
		sort_four(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	// else
	// 	sort(&stack_a, &stack_b);
	// ft_lstclear(&stack_a, free);
	// ft_lstclear(&instructions, free);

	// ft_printf("stack a:\n");
	// ft_lstiter(stack_a, print);
	ft_lstclear(&stack_a, free);
}

