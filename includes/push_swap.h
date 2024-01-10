/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:57:55 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/10 10:43:46 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

/*---------------------- Macro Functions ----------------------*/

// Swap the top elements of stack A and print "sa"
# define SA(A, B)(swap(A, B), ft_puts("sa"))

// Swap the top elements of stack B and print "sb"
# define SB(B, A)(swap(B, A), ft_puts("sb"))

// Swap the top elements of both stacks A and B, and print "ss"
# define SS(A, B, SZA, SZB)(swap(A, SZA),swap(B, SZB),ft_puts("ss"))

// Push the top element of stack A to stack B, and print "pa"
# define PA(A, B, size_A, size_B)(push(A, B, size_A, size_B),ft_puts("pa"))

// Push the top element of stack B to stack A, and print "pb"
# define PB(B, A, size_B, size_A)(push(B, A, size_B, size_A),ft_puts("pb"))

// Rotate stack A and print "ra"
# define RA(stack, size)(rotate(stack, size),ft_puts("ra"))

// Rotate stack B and print "rb"
# define RB(stack, size)(rotate(stack, size),ft_puts("rb"))

// Rotate both stacks A and B, and print "rr"
# define RR(A, B, SZA, SZB)(rotate(A,SZA),rotate(B,SZB),ft_puts("rr"))

// Reverse rotate stack A and print "rra"
# define RRA(stack, size)(rrotate(stack, size),ft_puts("rra"));

// Reverse rotate stack B and print "rrb"
# define RRB(stack, size)(rrotate(stack, size),ft_puts("rrb"));

// Reverse rotate both stacks A and B, and print "rrr"
# define RRR(A, B, SZA, SZB)(rrotate(A,SZA),rrotate(B,SZB),ft_puts("rrr"))

/*---------------------- Prototypes ----------------------*/

void	swap(int *stack, int size);

void	push(int *dst, int *src, int *sz_dst, int *sz_src);

void	rotate(int *stack, int size);

void	rrotate(int *stack, int size);

#endif
