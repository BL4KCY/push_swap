/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:57:59 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/09 21:56:16 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int *dst, int *src, int *sz_dst, int *sz_src)
{
	if (*sz_src > 0)
		dst[(*sz_dst)++] = src[--(*sz_src)];
}

void	swap(int *stack, int size)
{
	int	tmp;
	if (size > 1)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
}

void	rotate(int *stack, int size)
{
	int	tmp;
	int	index;

	index = -1;
	tmp = stack[size - 1];
	while (++index < size - 1)
		stack[size - index - 1] = stack[size - index - 2];
	stack[size - index - 1] = tmp;
}

void	rrotate(int *stack, int size)
{
	int	tmp;
	int	index;

	index = 0;
	tmp = stack[index];
	while (++index < size)
		stack[index - 1] = stack[index];
	stack[index - 1] = tmp;
}

