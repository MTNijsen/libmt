/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 15:40:20 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 14:29:58 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# define HOLD_SIZE	1024

# include "../libmt.h"

char	*get_next_line(int fd);

#endif
