/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houabell <houabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:00:52 by houabell          #+#    #+#             */
/*   Updated: 2024/12/05 02:03:08 by houabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_BONUS_H
# define FT_GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
#   define MAX_FD 1024
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*extract_line(char **stash);
char	*read_and_update(int fd, char **stash);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t destsize);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);


#endif
