/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houabell <houabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:00:42 by houabell          #+#    #+#             */
/*   Updated: 2024/12/05 02:15:21 by houabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line_bonus.h"

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
	static char	*stash[MAX_FD] = {NULL};
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_and_update(fd, &stash[fd]);
	if (!line)
	{
		free (stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	return (line);
}

