/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marccost <marccost@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:31:03 by marccost          #+#    #+#             */
/*   Updated: 2026/01/29 16:31:03 by marccost         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "libft.h"

char	*extract_line(char **storage)
{
	char	*line;
	char	*new_storage;
	int		i;

	i = 0;
	while ((*storage)[i] && (*storage)[i] != '\n')
		i++;
	line = ft_strdup(*storage);
	if (!line)
		return (NULL);
	line[i + ((*storage)[i] == '\n')] = '\0';
	new_storage = ft_strdup(*storage + i + ((*storage)[i] == '\n'));
	free(*storage);
	*storage = new_storage;
	return (line);
}

int	read_to_storage(int fd, char **storage)
{
	char	*buf;
	int		bytes_read;
	char	*temp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buf);
		return (-1);
	}
	buf[bytes_read] = '\0';
	temp = ft_strjoin(*storage, buf);
	free(*storage);
	*storage = temp;
	free(buf);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!storage || !ft_strchr(storage, '\n'))
	{
		bytes_read = read_to_storage(fd, &storage);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (NULL);
	}
	if (!storage || !*storage)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	line = extract_line(&storage);
	return (line);
}
