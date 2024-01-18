/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:47:56 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/18 11:03:18 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parse_args(int ac, char **av, t_stack **stack_a)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (++i < ac)
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j] || (!j && !split[j]))
		{
			if (!is_valid_arg(split[j], *stack_a) || (!j && !split[j]))
			{
				ft_free_split(split);
				ft_lstclear(stack_a);
				ERR();
			}
			ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(split[j++])));
		}
		ft_free_split(split);
	}
}

bool	is_valid_arg(char *arg, t_stack *stack_a)
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
	if ((ft_atoi(arg) > INT_MAX || ft_atoi(arg) < INT_MIN) || !i || !is_valid_num(arg))
		return (false);
	return (true);
}

bool	is_valid_num(char *arg)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_itoa(ft_atoi(arg));
	while (arg[i] && arg[i] == ' ')
		i++;
	while (arg[i] && arg[i] == '0')
		i++;
	if (ft_strlen(arg + i) > 0 && ft_strlen(tmp) != ft_strlen(arg + i))
	{
		free(tmp);
		return (false);
	}
	free(tmp);
	return (true);
}
