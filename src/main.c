/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:38:58 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/08 11:20:48 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int stack[] = {1,2,3,4,5};

	int size = sizeof(stack) / sizeof(stack[0]);
	swap(stack, size);
	for (int i = 0; i < size ;i++)
		ft_putnbr_fd(stack[i], 1);
	ft_putendl_fd("",1);
	swap(stack, size);
	for (int i = 0; i < size ;i++)
		ft_putnbr_fd(stack[i], 1);
}


