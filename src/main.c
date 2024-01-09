/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:38:58 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/09 21:57:47 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int stack_a[6] = {1,2,3,4,5};
	//int stack_b[6];// = {6,7,8,9,10};

	int size_a = 5;//sizeof(stack_a) / sizeof(stack_a[0]);
	//int size_b = 0;//sizeof(stack_b) / sizeof(stack_b[0]);

	for (int i = 0; i < size_a;i++)
		ft_printf("%d",stack_a[i]);

	rotate(stack_a, size_a);
	rrotate(stack_a, size_a);

	ft_puts("");

	for (int i = 0; i < size_a;i++)
		ft_printf("%d",stack_a[i]);




}
