/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_nmb.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 17:41:54 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/15 13:00:15 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_output	*ft_printf_dec(t_output *output, va_list args)
{
	ssize_t const	input = (ssize_t)va_arg(args, int);
	char			*str;

	str = d_to_base(input, "0123456789");
	if (!str)
		return (ft_printf_freeoutput(output));
	if (output->flag & PLUS && str[0] != '-')
		output = ft_printf_charappend(output, '+');
	else if (output->flag & SPACE && str[0] != '-')
		output = ft_printf_charappend(output, ' ');
	output = ft_printf_strappend(output, str);
	free(str);
	return (ft_printf_finish_flag(output, args));
}

t_output	*ft_printf_un_dec(t_output *output, va_list args)
{
	size_t const	input = (size_t)va_arg(args, unsigned int);
	char			*str;

	str = ud_to_base(input, "0123456789");
	if (!str)
		return (ft_printf_freeoutput(output));
	output = ft_printf_strappend(output, str);
	free(str);
	return (ft_printf_finish_flag(output, args));
}

t_output	*ft_printf_hex_l(t_output *output, va_list args)
{
	size_t const	input = (size_t)va_arg(args, unsigned int);
	char			*str;

	if (output->flag & HASH && input != 0)
	{
		output = ft_printf_strappend(output, "0x");
		if (!output)
			return (NULL);
	}
	str = ud_to_base(input, "0123456789abcdef");
	if (!str)
		return (ft_printf_freeoutput(output));
	output = ft_printf_strappend(output, str);
	free(str);
	return (ft_printf_finish_flag(output, args));
}

t_output	*ft_printf_hex_u(t_output *output, va_list args)
{
	size_t const	input = (size_t)va_arg(args, unsigned int);
	char			*str;

	if (output->flag & HASH && input != 0)
	{
		output = ft_printf_strappend(output, "0X");
		if (!output)
			return (NULL);
	}
	str = ud_to_base(input, "0123456789ABCDEF");
	if (!str)
		return (ft_printf_freeoutput(output));
	output = ft_printf_strappend(output, str);
	free(str);
	return (ft_printf_finish_flag(output, args));
}
