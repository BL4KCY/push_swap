/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:58:54 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/19 10:59:15 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

/*---------------------- Macro Functions ----------------------*/

// Swap the top elements of stack A and print "sa"
# define SA(A)(swap(A))

// Swap the top elements of stack B and print "sb"
# define SB(B)(swap(B))

// Swap both stacks tops A and B and print "ss"
# define SS(A, B)(swap(A), swap(B))

// Push the top element of stack A to stack B, and print "pa"
# define PA(A, B)(push(A, B))

// Push the top element of stack B to stack A, and print "pb"
# define PB(B, A)(push(B, A))

// Rotate stack A and print "ra"
# define RA(A)(rotate(A))

// Rotate stack B and print "rb"
# define RB(B)(rotate(B))

// Rotate both stacks A and B, and print "rr"
# define RR(A, B)(rotate(A),rotate(B))

// Reverse rotate stack A and print "rra"
# define RRA(A)(reverse_rotate(A));

// Reverse rotate stack B and print "rrb"
# define RRB(B)(reverse_rotate(B));

// Reverse rotate both stacks A and B, and print "rrr"
# define RRR(A, B)(reverse_rotate(A),reverse_rotate(B))

// Print an error message to standard error output
# define ERR()(ft_putendl_fd("Error", STDERR_FILENO),exit(EXIT_FAILURE))

/*---------------------- Prototypes ----------------------*/

void	push(t_stack **src, t_stack **dst);

void	swap(t_stack **lst);

void	rotate(t_stack **lst);

void	reverse_rotate(t_stack **lst);

void	parse_args(int ac, char **av, t_stack **stack_a);

void	ft_free_split(char **split);

bool	is_valid_num(char *arg);

bool	is_valid_arg(char *arg, t_stack *stack_a);

bool	exist(t_stack *stack, int value);

bool	is_sorted(t_stack *stack);

void	error(char *operation);

void	execute(char *operation, t_stack **stack_a, t_stack **stack_b);

int		push_case(char *operation, t_stack **stack_a, t_stack **stack_b);

int		swap_case(char *operation, t_stack **stack_a, t_stack **stack_b);

int		rotate_case(char *operation, t_stack **stack_a, t_stack **stack_b);

int		rev_rotate_case(char *operation, t_stack **stack_a, t_stack **stack_b);

#endif
