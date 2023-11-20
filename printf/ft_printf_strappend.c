/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_strappend.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 23:24:55 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/15 13:07:39 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_array_join(char const *s1, char const *s2, size_t len_s1)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = ft_strlen(s2);
	str = (char *)ft_calloc(len_s1 + j + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	return (str);
}

t_output	*ft_printf_strappend(t_output *output, const char *s2)
{
	char	*str;

	if (!s2)
		return (ft_printf_freeoutput(output));
	if (!output)
		return (NULL);
	str = char_array_join(output->str, s2, output->len);
	output->len += ft_strlen(s2);
	free(output->str);
	if (!str)
		return (free(output), NULL);
	output->str = str;
	return (output);
}

t_output	*ft_printf_charappend(t_output *output, char const c)
{
	char	*str;
	size_t	i;

	str = ft_calloc(output->len +2, sizeof(char));
	if (!str)
		return (ft_printf_freeoutput(output));
	i = 0;
	while (i < output->len)
	{
		str[i] = output->str[i];
		i++;
	}
	str[i] = c;
	free(output->str);
	output->str = str;
	output->len++;
	return (output);
}
