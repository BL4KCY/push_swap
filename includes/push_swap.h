/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:57:55 by melfersi          #+#    #+#             */
/*   Updated: 2024/01/09 21:48:41 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

/*____________________macros functions____________________*/

# define SA(stack_a, size_a)(swap(stack_a, size_a), ft_puts("sa"))

# define SB(stack_b, size_b)(swap(stack_b, size_b), ft_puts("sb"))

# define SS(sa, sb, sza, szb)(swap(sa, sza),swap(sb, szb),ft_puts("ss"))

# define PA(a, b, size_a, size_b)(push(a, b, size_a, size_b),ft_puts("pa"))

# define PB(b, a, size_b, size_a)(push(b, a, size_b, size_a),ft_puts("pb"))

/*____________________Prototypes____________________*/

void	swap(int *stack, int size);

void	push(int *dst, int *src, int *sz_dst, int *sz_src);

void	rotate(int *stack, int size);

void	rrotate(int *stack, int size);

#endif
