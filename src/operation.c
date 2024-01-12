/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:06:05 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/12 10:38:54 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (ft_lstsize(*src) > 0)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
	}
}

void	swap(t_list **lst)
{
	t_list	*tmp;

	if (ft_lstsize(*lst) > 1)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = (*lst)->next;
		(*lst)->next = tmp;
	}
}

void	rotate(t_list **lst)
{
	t_list	*tmp;

	if (ft_lstsize(*lst) > 1)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = NULL;
		ft_lstadd_back(lst, tmp);
	}
}

void	reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;

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
