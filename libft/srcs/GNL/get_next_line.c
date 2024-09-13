/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melina <melina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:13:12 by memotyle          #+#    #+#             */
/*   Updated: 2024/08/13 14:55:13 by melina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_storage(char **storage)
{
	if (*storage)
	{
		free(*storage);
		*storage = NULL;
	}
	return (NULL);
}

static int	join_storage_and_buffer(char **storage, char *buffer)
{
	char	*temp;

	if (!*storage)
	{
		*storage = ft_strdup_gnl(buffer);
		if (!*storage)
			return (0);
	}
	else
	{
		temp = ft_strjoin(*storage, buffer);
		if (!temp)
			return (0);
		free_storage(storage);
		*storage = temp;
	}
	return (1);
}

static char	*generate_line(char **storage)
{
	size_t	len;
	char	*line;
	char	*temp;

	if (!*storage || **storage == '\0')
		return (NULL);
	if (ft_strchr(*storage, '\n'))
		len = ft_strchr(*storage, '\n') - *storage + 1;
	else
		len = ft_strlen(*storage);
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *storage, len + 1);
	if (ft_strchr(*storage, '\n'))
	{
		temp = ft_strdup_gnl(ft_strchr(*storage, '\n') + 1);
		free_storage(storage);
		*storage = temp;
	}
	else
		free_storage(storage);
	return (line);
}

static int	ft_read(int fd, char **storage)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (!join_storage_and_buffer(storage, buffer))
		{
			free(buffer);
			return (-1);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX - 1)
		return (NULL);
	bytes_read = ft_read(fd, &storage);
	if (bytes_read < 0 || (bytes_read == 0 && (!storage || !*storage)))
		return (free_storage(&storage));
	line = generate_line(&storage);
	if (!line || *line == '\0')
	{
		free(line);
		return (free_storage(&storage));
	}
	return (line);
}


// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	int fd;
// 	char *line;
// 	char *name = "gnl.txt";

// 	fd = open(name, O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }
