/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:42:46 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/28 14:01:20 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*my_read_line(int fd, char **reminder)
{
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(*reminder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(*reminder);
			*reminder = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		*reminder = ft_strjoin(*reminder, buffer);
	}
	free(buffer);
	return (*reminder);
}

static char	*our_line(char *staart)
{
	int		i;
	char	*line;

	i = 0;
	while (staart[i] && staart[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (staart[i] && staart[i] != '\n')
	{
		line[i] = staart[i];
		i++;
	}
	if (staart[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*tmp;
	char		*line;
	char		*search;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(reminder), reminder = NULL, NULL);
	my_read_line(fd, &reminder);
	search = ft_strchr(reminder, '\n');
	if (reminder && !search)
	{
		tmp = ft_strdup(reminder);
		free(reminder);
		return (reminder = NULL, tmp);
	}
	else if (reminder && search)
	{
		tmp = reminder;
		line = our_line(reminder);
		reminder = ft_strdup(search + 1);
		return (free(tmp), line);
	}
	return (NULL);
}
