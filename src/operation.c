/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:06:05 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/15 10:29:08 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (ft_lstsize(*src) > 0)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
	}
}

void	swap(t_stack **lst)
{
	t_stack	*tmp;

	if (ft_lstsize(*lst) > 1)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = (*lst)->next;
		(*lst)->next = tmp;
	}
}

void	rotate(t_stack **lst)
{
	t_stack	*tmp;

	if (ft_lstsize(*lst) > 1)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = NULL;
		ft_lstadd_back(lst, tmp);
	}
}

void	reverse_rotate(t_stack **lst)
{
	t_stack	*tmp;
	t_stack	*last;

	if (ft_lstsize(*lst) > 1)
	{
		tmp = *lst;
		last = ft_lstlast(*lst);
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		ft_lstadd_front(lst, last);
	}
}
