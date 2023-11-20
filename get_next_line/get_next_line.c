/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 22:01:37 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:14:35 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*read_valid_line(char *hold[], int fd, \
				char buffer[], ssize_t bytes_read);
static int		read_further(char *hold[], int fd, \
				char buffer[], ssize_t bytes_read);
static ssize_t	read_larger(int fd, char *buffer);
static char		*ft_strappend(char const *s1, char const *s2);

char	*get_next_line(int fd)
{
	static char			*hold[1024] = {0};
	char				*output;
	char				*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (ft_bzero(hold[fd], 1), NULL);
	if (BUFFER_SIZE > HOLD_SIZE)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	else
		buffer = ft_calloc(HOLD_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		if (hold[fd])
			free(hold[fd]);
		hold[fd] = NULL;
		return (NULL);
	}
	output = read_valid_line(hold, fd, buffer, 0);
	free(buffer);
	if (output && !*output)
		return (free(output), NULL);
	return (output);
}

static char	*read_valid_line(char *hold[], int fd, \
		char buffer[], ssize_t bytes_read)
{
	char	*output;
	char	*temp;
	int		output_len;

	output_len = read_further(hold, fd, buffer, bytes_read);
	if (output_len == -1)
		return (NULL);
	output = ft_substr(hold[fd], 0, output_len);
	if (output && ft_strchr(output, '\n') != NULL)
	{
		temp = ft_substr(hold[fd], output_len, 0);
		if (hold[fd])
			free (hold[fd]);
		hold[fd] = temp;
		if (!temp)
			return (free(output), NULL);
	}
	else
	{
		if (hold[fd])
			free (hold[fd]);
		hold[fd] = NULL;
	}
	return (output);
}

static int	read_further(char *hold[], int fd, \
			char buffer[], ssize_t bytes_read)
{
	int		output_len;
	char	*temp;

	output_len = -1;
	while (output_len < 0)
	{
		bytes_read = read_larger(fd, buffer);
		if (bytes_read < 0)
			return (-1);
		temp = ft_strappend(hold[fd], buffer);
		if (hold[fd])
		{
			free(hold[fd]);
			hold[fd] = NULL;
		}
		if (temp == NULL)
			return (-1);
		hold[fd] = temp;
		if (ft_strchr(hold[fd], '\n') != NULL)
			output_len = (size_t)ft_strchr(hold[fd],
					'\n') - (size_t)hold[fd] + 1;
		else if (bytes_read == 0)
			output_len = ft_strlen(hold[fd]);
	}
	return (output_len);
}

static ssize_t	read_larger(int fd, char buffer[])
{
	ssize_t	bytes_read;
	size_t	i;

	i = 0;
	bytes_read = 1;
	if (BUFFER_SIZE > HOLD_SIZE)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	else
	{
		ft_bzero(buffer, HOLD_SIZE);
		while (i + BUFFER_SIZE <= HOLD_SIZE && !ft_strchr(buffer, '\n')
			&& bytes_read > 0)
		{
			bytes_read = read(fd, &buffer[i], BUFFER_SIZE);
			i += BUFFER_SIZE;
		}
	}
	return (bytes_read);
}

static char	*ft_strappend(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1 && s1[i++])
		;
	while (s2 && s2[j++])
		;
	if (i == 0 && j == 0)
		return (NULL);
	str = (char *)ft_calloc(i + j + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	return (str);
}
// int main()
// {
// 	int fd = open("test1", O_RDONLY);

// 	char *line;
// 	line = get_next_line(fd);

// 	while (line)
// 	{
// 		printf("-- %s", line);
// 		if (line == NULL)
// 			printf("\n");
// 		free(line);
// 		line = get_next_line(fd);
// 	}

// }