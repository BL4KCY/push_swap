/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:38:58 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/08 11:43:22 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int stack_a[] = {1,2,3,4,5};
	int stack_b[] = {5,4,3,2,1};

	int size_a = sizeof(stack_a) / sizeof(stack_a[0]);
	int size_b = sizeof(stack_b) / sizeof(stack_b[0]);

	SA(stack_a, size_a);
	for (int i = 0; i < size_a ;i++)
		ft_putnbr_fd(stack_a[i], 1);
	ft_putendl_fd("",1);
	SA(stack_a, size_a);
	for (int i = 0; i < size_a ;i++)
		ft_putnbr_fd(stack_a[i], 1);

	ft_putendl_fd("",1);

	SB(stack_b, size_b);
	for (int i = 0; i < size_b ;i++)
		ft_putnbr_fd(stack_b[i], 1);
	ft_putendl_fd("",1);
	SB(stack_b, size_b);
	for (int i = 0; i < size_b ;i++)
		ft_putnbr_fd(stack_b[i], 1);
}
