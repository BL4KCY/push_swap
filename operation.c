/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:57:59 by melfersi          #+#    #+#             */
/*   Updated: 2023/12/24 10:59:59 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *stack, size_t *top, size_t size)
{
	char	tmp;

	if (top >= 1)
	{
		tmp = stack[top - 1];
		stack[top - 1] = stack[top - 2];
		stack[top - 2] = tmp;
	}
}

void	push(char *dst, char *src, size_t *top_dst, size_t *top_src, size_t size)
{
		
}
