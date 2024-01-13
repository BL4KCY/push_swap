/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:57:55 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/13 22:17:55 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

/*---------------------- Macro Functions ----------------------*/

// Swap the top elements of stack A and print "sa"
# define SA(A)(swap(A), ft_puts("sa"))

// Swap the top elements of stack B and print "sb"
# define SB(B)(swap(B), ft_puts("sb"))

// Swap the top elements of both stacks A and B, and print "ss"
# define SS(A, B)(swap(A),swap(B),ft_puts("ss"))

// Push the top element of stack A to stack B, and print "pa"
# define PA(A, B)(push(A, B),ft_puts("pa"))

// Push the top element of stack B to stack A, and print "pb"
# define PB(B, A)(push(B, A),ft_puts("pb"))

// Rotate stack A and print "ra"
# define RA(A)(rotate(A),ft_puts("ra"))

// Rotate stack B and print "rb"
# define RB(B)(rotate(B),ft_puts("rb"))

// Rotate both stacks A and B, and print "rr"
# define RR(A, B)(rotate(A),rotate(B),ft_puts("rr"))

// Reverse rotate stack A and print "rra"
# define RRA(A)(reverse_rotate(A),ft_puts("rra"));

// Reverse rotate stack B and print "rrb"
# define RRB(B)(reverse_rotate(B),ft_puts("rrb"));

// Reverse rotate both stacks A and B, and print "rrr"
# define RRR(A, B)(reverse_rotate(A),reverse_rotate(B),ft_puts("rrr"))

// Print an error message to standard error output
# define ERR()(ft_putendl_fd("Error", STDERR_FILENO),exit(EXIT_FAILURE))

/*---------------------- Prototypes ----------------------*/

void	push(t_list **src, t_list **dst);

void	swap(t_list **lst);

void	rotate(t_list **lst);

void	reverse_rotate(t_list **lst);

void	push_swap(int ac, char **av);

void	parse_args(int ac, char **av, t_list **stack_a);

void	ft_free_split(char **split);

bool	is_valid_arg(char *arg, t_list *stack_a);

bool	exist(t_list *stack, int value);

bool	is_sorted(t_list *stack);

void	sort_three(t_list **stack_a);

void	sort_four(t_list **stack_a, t_list **stack_b);

void	sort_five(t_list **stack_a, t_list **stack_b);

int		get_max(t_list *stack);

int		get_min(t_list *stack);

bool	is_valid_num(char *arg);

#endif
