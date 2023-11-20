/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 20:13:26 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:18:08 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (16384);
	}
	else
	{
		return (0);
	}
}
