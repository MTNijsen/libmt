/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_freeoutput.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 10:12:20 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/13 17:40:40 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_output	*ft_printf_freeoutput(t_output *output)
{
	if (!output)
		return (NULL);
	free(output->str);
	free(output);
	output = NULL;
	return (output);
}
