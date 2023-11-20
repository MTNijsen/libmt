/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_str.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 17:45:47 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/13 18:03:43 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_output	*ft_printf_char(t_output *output, va_list args)
{
	char const	input = (char)va_arg(args, int);

	output = ft_printf_charappend(output, input);
	return (ft_printf_finish_flag(output, args));
}

t_output	*ft_printf_str(t_output *output, va_list args)
{
	char const	*input = va_arg(args, char *);

	if (!input)
		output = ft_printf_strappend(output, "(null)");
	else
		output = ft_printf_strappend(output, input);
	return (ft_printf_finish_flag(output, args));
}

t_output	*ft_printf_ptr(t_output *output, va_list args)
{
	size_t const	input = (size_t)va_arg(args, void *);
	char			*str;

	if (input != 0)
	{
		str = ud_to_base(input, "0123456789abcdef");
		output = ft_printf_strappend(output, "0x");
	}
	else
		str = ft_strdup("(nil)");
	if (!str)
		return (ft_printf_freeoutput(output));
	output = ft_printf_strappend(output, str);
	free(str);
	return (ft_printf_finish_flag(output, args));
}

t_output	*ft_printf_perc(t_output *output, va_list args)
{
	char const	input = '%';

	if (args)
		;
	output = ft_printf_charappend(output, input);
	return (ft_printf_finish_flag(output, args));
}
