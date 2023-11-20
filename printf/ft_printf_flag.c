/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_flag.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/11 12:50:34 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/15 13:30:10 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_output	*ft_printf_sign_flag(t_output *output, va_list args)
{
	if (!output)
		return (output);
	if (output->flag & SPACE)
		output->flag ^= SPACE;
	output->flag |= PLUS;
	if (args)
		;
	return (output);
}

t_output	*ft_printf_space_flag(t_output *output, va_list args)
{
	if (!output)
		return (output);
	if (output->flag & PLUS)
		return (output);
	output->flag |= SPACE;
	if (args)
		;
	return (output);
}

t_output	*ft_printf_hash_flag(t_output *output, va_list args)
{
	if (!output)
		return (output);
	output->flag |= HASH;
	if (args)
		;
	return (output);
}

t_output	*ft_printf_finish_flag(t_output *output, va_list args)
{
	if (!output)
		return (output);
	output->flag |= F;
	if (args)
		;
	return (output);
}

// + = 1ul << 0
//   = 1ul << 1
// # = 1ul << 2
