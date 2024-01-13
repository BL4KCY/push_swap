/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:47:56 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/13 10:21:09 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(int ac, char **av, t_list **stack_a)
{
	int		i;
	int		j;
	char	**split;
	int		*value;
	i = 0;
	while (++i < ac)
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j] || (!j && !split[j]))
		{
			value = malloc(sizeof(int));
			if (!is_valid_arg(split[j], *stack_a) || !value || (!j && !split[j]))
			{
				if (value)
					free(value);
				ft_free_split(split);
				ft_lstclear(stack_a, free);
				ERR();
			}
			*value = ft_atoi(split[j++]);
			ft_lstadd_back(stack_a, ft_lstnew(value));
		}
		ft_free_split(split);
	}
}

bool	is_valid_arg(char *arg, t_list *stack_a)
{
	int	i;
	int	sign;

	i = -1;
	sign = 0;
	if (!arg)
		return (false);
	if (exist(stack_a, ft_atoi(arg)))
		return (false);
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-' && arg[i] != '+' && arg[i] != ' ')
			return (false);
		if(arg[i] == '-' || arg[i] == '+')
			sign++;
		if (sign > 1)
			return (false);
	}
	if ((ft_atoi(arg) > INT_MAX || ft_atoi(arg) < INT_MIN) || !i)
		return (false);
	return (true);
}

bool	exist(t_list *stack, int value)
{
	while (stack)
	{
		if (*(int *)stack->content == value)
			return (true);
		stack = stack->next;
	}
	return (false);
}

void	ft_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}
