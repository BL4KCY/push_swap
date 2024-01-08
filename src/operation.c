/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:57:59 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/08 11:38:06 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack, int size, char *op)
{
	int	tmp;
	if (size > 1)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
		ft_putendl_fd(op, STDOUT_FILENO);
	}
}
