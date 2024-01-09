/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:38:58 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/09 18:02:27 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int stack_a[6] = {1,2,3,4,5};
	int stack_b[6];// = {6,7,8,9,10};

	int size_a = 6;//sizeof(stack_a) / sizeof(stack_a[0]);
	int size_b = 1;//sizeof(stack_b) / sizeof(stack_b[0]);

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

	ft_putendl_fd("",1);
	SS(stack_a, stack_b, size_a, size_b);
	for (int i = 0; i < size_a ;i++)
		ft_putnbr_fd(stack_a[i], 1);
	ft_putendl_fd("",1);
	for (int i = 0; i < size_b ;i++)
		ft_putnbr_fd(stack_b[i], 1);

	ft_putendl_fd("",1);
	PA(stack_a, stack_b, &size_a, &size_b);
	for (int i = 0; i < size_a ;i++)
		ft_putnbr_fd(stack_a[i], 1);
	ft_putendl_fd("",1);
	for (int i = 0; i < size_b ;i++)
		ft_putnbr_fd(stack_b[i], 1);



}
