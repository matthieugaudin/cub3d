/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:26:24 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/27 09:36:44 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	skip_space(char **s)
{
	while (**s && **s == 32)
		(*s)++;
}

int	check_cross(char **map, int j, int i)
{
	if (i == 0 || j == 0)
		return (0);
	if (!map[j] || !map[j][i])
		return (0);
	if (map[j - 1][i] == 'X')
		return (0);
	if (map[j + 1][i] == 'X')
		return (0);
	if (map[j][i + 1] == 'X')
		return (0);
	if (map[j][i - 1] == 'X')
		return (0);
	return (1);
}

void	map_end(t_data *data, char *line)
{
	free(line);
	line = get_next_line(data->fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(data->fd);
	}
	if (line)
	{
		free(line);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("some chars are present after the map", 2);
		free_data(&data);
		exit(0);
	}
	free(line);
}
