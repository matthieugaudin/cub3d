/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:42:02 by ndelhota          #+#    #+#             */
/*   Updated: 2025/04/23 11:58:42 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strchr_gnl(char *s, char seek)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (-1);
	while (s[i])
	{
		if (s[i] == seek)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen_gnl(char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_readjust_remain(char *s, int start)
{
	int		i;
	char	*new_remain;

	i = ft_strlen_gnl(s + start);
	new_remain = malloc(i + 1);
	if (!new_remain)
		return (NULL);
	i = 0;
	while (s[start + i])
	{
		new_remain[i] = s[start + i];
		i++;
	}
	new_remain[i] = 0;
	free(s);
	return (new_remain);
}

char	*ft_memcpy_gnl(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (n--)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_substr_gnl(char *s, int start, int len)
{
	int		i;
	char	*sub;

	i = ft_strlen_gnl(s);
	if (!s || start > i)
		return (NULL);
	i = i - start;
	if (i > len)
		i = len;
	sub = malloc(i + 1);
	if (!sub)
	{
		free(s);
		return (0);
	}
	ft_memcpy_gnl(sub, s + start, i);
	sub[i] = '\0';
	return (sub);
}
