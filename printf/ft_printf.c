/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 17:40:57 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/15 13:29:57 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flag_table(void **flag_table)
{
	flag_table['c'] = &ft_printf_char;
	flag_table['s'] = &ft_printf_str;
	flag_table['p'] = &ft_printf_ptr;
	flag_table['d'] = &ft_printf_dec;
	flag_table['i'] = &ft_printf_dec;
	flag_table['u'] = &ft_printf_un_dec;
	flag_table['x'] = &ft_printf_hex_l;
	flag_table['X'] = &ft_printf_hex_u;
	flag_table['%'] = &ft_printf_perc;
	flag_table['+'] = &ft_printf_sign_flag;
	flag_table[' '] = &ft_printf_space_flag;
	flag_table['#'] = &ft_printf_hash_flag;
}

t_output	*add_flag(const char str, va_list args,
	t_output *output, void **flag_table)
{
	t_output	*(*f)(t_output *, va_list);

	if (flag_table[(int)str])
	{
		f = flag_table[(int)str];
		output = f(output, args);
	}
	return (output);
}

t_output	*assemble_output(const char *str,
	va_list args, t_output *output, void **flag_table)
{
	char		*str_till_perc;
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			while (str[++i] && flag_table[(int)str[i]] && !(output->flag & F))
			{
				output = add_flag(str[i], args, output, flag_table);
				if (!output)
					return (output);
			}
		}
		output->flag = 0;
		str_till_perc = ft_strndup(&str[i],
				ft_strchr_null(&str[i], '%') - &str[i]);
		output = ft_printf_strappend(output, str_till_perc);
		free(str_till_perc);
		if (!output)
			return (NULL);
		i += ft_strchr_null(&str[i], '%') - &str[i];
	}
	return (output);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_output	*output;
	void		*flag_table[256];
	size_t		len;

	init_flag_table(flag_table);
	output = ft_calloc(1, sizeof(t_output));
	if (!output)
		return (-1);
	va_start(args, str);
	output = assemble_output(str, args, output, (void **)flag_table);
	va_end(args);
	if (!output)
		return (-1);
	len = output->len;
	if (output)
		write(1, output->str, output->len);
	ft_printf_freeoutput(output);
	return (len);
}
