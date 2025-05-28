/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:10:59 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/26 15:15:51 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	*insert_line(t_data *data, char *line)
{
	char	*to_ret;
	size_t	i;

	i = 0;
	to_ret = malloc(sizeof(char) * (data->map_width + 1));
	if (!to_ret)
		return (NULL);
	while (line [i] && line[i] != '\n')
	{
		if (line[i] == 32)
			to_ret[i] = 'X';
		else
			to_ret[i] = line[i];
		i++;
	}
	while (i < data->map_width)
	{
		to_ret[i] = 'X';
		i++;
	}
	to_ret[i] = 0;
	return (to_ret);
}

void	create_tab_line(t_data *data, char **tab, char *line)
{
	*tab = insert_line(data, line);
	free(line);
	line = get_next_line(data->fd);
	while (line && *line != '\n')
	{
		tab++;
		*tab = insert_line(data, line);
		free(line);
		line = get_next_line(data->fd);
	}
	if (line && *line == '\n')
		gnl_trap(data);
	free(line);
	tab++;
	*tab = NULL;
}

char	*skip_to_map(t_data *data)
{
	char	*line;

	line = get_next_line(data->fd);
	if (!line)
		return (line);
	while (check_all(line) || *line == '\n')
	{
		free(line);
		line = get_next_line(data->fd);
	}
	return (line);
}

void	get_map(t_data *data, char *map_name)
{
	char	*line;

	data->fd = open(map_name, O_RDONLY);
	line = skip_to_map(data);
	create_tab_line(data, data->map, line);
	close(data->fd);
	data->fd = 0;
}
