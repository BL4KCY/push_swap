/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:57:55 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/19 17:58:36 by melfersi         ###   ########.fr       */
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

// Swap both stacks tops A and B and print "ss"
# define SS(A, B)(swap(A), swap(B), ft_puts("ss"))

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

// Function to push the top element from src stack to dst stack
void	push(t_stack **src, t_stack **dst);

// Function to swap the top two elements of a stack
void	swap(t_stack **lst);

// Function to rotate the stack by moving the top element to the bottom
void	rotate(t_stack **lst);

// Function to reverse rotate the stack by moving the bottom element to the top
void	reverse_rotate(t_stack **lst);

// Function to parse command line arguments and create stack_a
void	parse_args(int ac, char **av, t_stack **stack_a);

// Function to free the memory allocated for a string array
void	ft_free_split(char **split);

// check if an argument is a valid integer and not already present in stack_a
bool	is_valid_arg(char *arg, t_stack *stack_a);

// Function to check if a value exists in the stack
bool	exist(t_stack *stack, int value);

// Function to check if the stack is sorted in ascending order
bool	is_sorted(t_stack *stack);

// Function to sort a stack of three elements
void	sort_three(t_stack **stack_a);

// Function to sort the stacks using the push_swap algorithm
void	sort_stacks(t_stack **a, t_stack **b);

// Function to assign current index to each node in the stack
void	current_index(t_stack *stack);

// Function to set the target index for each node in stack_a
void	set_target_a(t_stack *a, t_stack *b);

// Function to set the target index for each node in stack_b
void	set_target_b(t_stack *a, t_stack *b);

// Function to calculate the cost of moving each node from stack_b to stack_a
void	cost_to_a(t_stack *a, t_stack *b);

// Function to set the cheapest node to move from stack_b to stack_a
void	set_cheapest(t_stack *stack);

// Function to push the top element from stack_b to stack_a
void	push_a(t_stack **a, t_stack **b);

// Function to push the top element from stack_a to stack_b
void	push_b(t_stack **a, t_stack **b);

// Function to initialize the nodes in stack_a with default values
void	init_a_nodes(t_stack *a, t_stack *b);

// Function to initialize the nodes in stack_b with default values
void	init_b_nodes(t_stack *a, t_stack *b);

// Function to move the minimum value to the top of the stack
void	max_to_top(t_stack **stack);

// arrange the stack by moving the top element to the specified position
void	arrange(t_stack **stack, t_stack *top, char c);

// Function to get the node with the cheapest value in the stack
t_stack	*get_cheapest(t_stack *stack);

// Function to get the node with the minimum value in the stack
t_stack	*get_min(t_stack *stack);

// Function to get the node with the maximum value in the stack
t_stack	*get_max(t_stack *stack);

// Function to check if a string argument is a valid number
bool	is_valid_num(char *arg);

// rotate both stacks A and B by moving the top elements to the bottom
void	both_rrotate(t_stack **a, t_stack **b, t_stack *top);

// rotate both stacks A and B by moving the bottom elements to the top
void	both_rotate(t_stack **a, t_stack **b, t_stack *top);

// Function to sort a stack of five elements
void	sort_five(t_stack **a, t_stack **b);

#endif
