/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houabell <houabell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:00:49 by houabell          #+#    #+#             */
/*   Updated: 2024/12/05 01:49:10 by houabell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	src_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	if (destsize > 0)
	{
		if (src_len < destsize - 1)
			copy_len = src_len;
		else
			copy_len = destsize - 1;
		while (copy_len > 0)
		{
			*dst = *src;
			dst++;
			src++;
			copy_len--;
		}
		*dst = '\0';
	}
	return (src_len);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	ptr = malloc(len + 1);
	i = 0;
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
    size_t	len1;
    size_t	len2;
    size_t	i;
    size_t	j;
    char	*result;

    if (!s1)
        s1 = ft_strdup("");
    if (!s2)
        return (s1);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    result = malloc(len1 + len2 + 1);
    if (!result)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        result[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';
    free(s1);
    return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	c = (char)c;
	while (*p)
	{
		if (*p == c)
		{
			return (p);
		}
		p++;
	}
	if (*p == c)
	{
		return (p);
	}
	return (NULL);
}
