/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:30:23 by ndelhota          #+#    #+#             */
/*   Updated: 2024/10/29 11:41:20 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill(char *new_remain, int fd)
{
	char	*r1;

	while (ft_strchr(new_remain, '\n') < 0)
	{
		r1 = read_l(fd);
		if (!r1)
			return (new_remain);
		new_remain = ft_join(new_remain, r1);
	}
	return (new_remain);
}

char	*ft_join(char *s1, char *s2)
{
	char	*new_remain;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_remain = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_remain)
		return (NULL);
	while (s1 && s1[i])
	{
		new_remain[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		new_remain[i + j] = s2[j];
		j++;
	}
	new_remain[i + j] = 0;
	free(s1);
	free(s2);
	return (new_remain);
}

char	*read_l(int fd)
{
	int		i;
	char	*buffer;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((sizeof(char) * BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = read(fd, buffer, BUFFER_SIZE);
	if (i <= 0)
		return (free(buffer), NULL);
	buffer[i] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*r1;
	static char	*remain;
	int			i;	

	remain = ft_fill(remain, fd);
	if (ft_strlen(remain) == 0 && remain != NULL)
	{
		free(remain);
		remain = NULL;
	}
	if (remain == NULL)
		return (remain);
	i = ft_strchr(remain, '\n');
	if (i >= 0)
	{
		r1 = ft_substr(remain, 0, i + 1);
		remain = ft_readjust_remain(remain, i + 1);
	}
	else
	{
		r1 = remain;
		remain = NULL;
	}
	return (r1);
}
