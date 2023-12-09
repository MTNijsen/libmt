/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 11:50:35 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/22 18:30:25 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libmt.h"

# define PLUS 1
# define SPACE 2
# define HASH 4
# define F 8

typedef struct s_output
{
	char		*str;
	char		flag;
	size_t		len;
}	t_output;

t_output	*ft_printf_strappend(t_output *s1, const char *s2);
size_t		ft_strlen(const char *s);
char		*ud_to_base(size_t input, char *base_chars);
char		*d_to_base(ssize_t input, char *base_chars);
int			ft_printf(const char *input_str, ...);
t_output	*ft_printf_freeoutput(t_output *output);
t_output	*ft_printf_charappend(t_output *output, char const c);

t_output	*ft_printf_sign_flag(t_output *output, va_list args);
t_output	*ft_printf_space_flag(t_output *output, va_list args);
t_output	*ft_printf_hash_flag(t_output *output, va_list args);
t_output	*ft_printf_finish_flag(t_output *output, va_list args);

t_output	*ft_printf_dec(t_output *output, va_list args);
t_output	*ft_printf_un_dec(t_output *output, va_list args);
t_output	*ft_printf_hex_l(t_output *output, va_list args);
t_output	*ft_printf_hex_u(t_output *output, va_list args);

t_output	*ft_printf_char(t_output *output, va_list args);
t_output	*ft_printf_str(t_output *output, va_list args);
t_output	*ft_printf_ptr(t_output *output, va_list args);
t_output	*ft_printf_perc(t_output *output, va_list args);
#endif