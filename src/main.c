/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:38:58 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/12 11:32:13 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(void *content)
{
	ft_putnbr_fd(*(int *)content, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}
int	main(void)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	for (int i = 1; i <= 10; i++)
	{
		int	*content = malloc(sizeof(int));
		*content = i;
		ft_lstadd_back(&stack_a, ft_lstnew(content));
	}
	ft_printf("stack a:\n");
	ft_lstiter(stack_a, print);
	ft_printf("stack b:\n");
	ft_lstiter(stack_b, print);
	ft_lstclear(&stack_a, free);
}
