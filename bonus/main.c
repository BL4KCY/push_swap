/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:24:42 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/18 12:34:30 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*operation;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	parse_args(ac, av, &stack_a);
	operation = get_next_line(STDIN_FILENO);
	while (operation)
	{
		execute(operation, &stack_a, &stack_b);
		free(operation);
		operation = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	return (0);
}

void	execute(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (!push_case(operation, stack_a, stack_b))
		if (!swap_case(operation, stack_a, stack_b))
			if (!rotate_case(operation, stack_a, stack_b))
				if (!rev_rotate_case(operation, stack_a, stack_b))
					error(operation);
}

void	error(char *operation)
{
	free(operation);
	ERR();
}
