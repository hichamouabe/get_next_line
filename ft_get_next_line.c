/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houabell <houabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 02:30:00 by assistant         #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

char	*extract_line(char **stash)
{
	char	*line;
	char	*newline;
	char	*remaining;
	int		line_len;

	if (!*stash || **stash == '\0')
		return (NULL);
	newline = ft_strchr(*stash, '\n');
	if (!newline)
	{
		line = ft_strdup(*stash);
		free (*stash);
		*stash = NULL;
		return (line);
	}
	line_len = newline - *stash + 1;
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *stash, line_len + 1);
	remaining = ft_strdup(newline + 1);
	free (*stash);
	*stash = remaining;
	return (line);
}

char	*read_and_update(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*line;

	if (!*stash)
		*stash = ft_strdup("");
	if (!*stash)
		return (NULL);
	while (!ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		*stash = ft_strjoin(*stash, buffer);
		if (!*stash)
			return (NULL);
	}
	line = extract_line(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_and_update(fd, &stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (line);
}
