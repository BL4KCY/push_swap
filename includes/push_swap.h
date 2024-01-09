/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:57:55 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/09 22:11:40 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

/*____________________macros functions____________________*/

# define SA(A, B)(swap(A, B), ft_puts("sa"))

# define SB(B, A)(swap(B, A), ft_puts("sb"))

# define SS(A, B, SZA, SZB)(swap(A, SZA),swap(B, SZB),ft_puts("ss"))

# define PA(A, B, size_A, size_B)(push(A, B, size_A, size_B),ft_puts("pa"))

# define PB(B, A, size_B, size_A)(push(B, A, size_B, size_A),ft_puts("pb"))

# define RA(stack, size)(rotate(stack, size),ft_puts("ra"))

# define RB(stack, size)(rotate(stack, size),ft_puts("rb"))

# define RR(A, B, SZA, SZB)(rotate(A,SZA),rotate(B,SZB),ft_puts("rr"))

/*____________________Prototypes____________________*/

void	swap(int *stack, int size);

void	push(int *dst, int *src, int *sz_dst, int *sz_src);

void	rotate(int *stack, int size);

void	rrotate(int *stack, int size);

#endif
