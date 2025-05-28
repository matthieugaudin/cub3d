/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_intel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:52:24 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/26 13:53:23 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	parse_count_line(t_data *data, char *line)
{
	char	*to_free;

	to_free = line;
	while (*line && *line != '\n')
	{
		if (*line == '1' || *line == '0' || *line == 32)
			line++;
		else if ((*line >= 'A' && *line <= 'Z')
			&& data->checkstart & 1ULL << ((*line) - 'A'))
		{
			if (data->checkstart & 1ULL << 63)
				multiple_start(data, to_free);
			else
				data->checkstart |= 1ULL << 63;
			line++;
		}
		else
			invalid_char(data, to_free);
	}
	if ((ft_strlen(to_free)) - 1 > data->map_width)
		data->map_width = ft_strlen(to_free) - 1;
}

void	get_tab_intel(t_data *data, int fd, char *line)
{
	int	length;

	length = 0;
	while (line)
	{
		if (ft_strlen(line) == 1 && *line == '\n')
		{
			map_end(data, line);
			data->map_length = length;
			return ;
		}
		parse_count_line(data, line);
		free(line);
		line = get_next_line(fd);
		length++;
	}
	data->map_length = length;
}

int	is_intel(t_data *data, char *line, int *six)
{
	int	i;

	i = 0;
	if (ft_strlen(line) == 1 && *line == '\n')
		return (1);
	i = check_all(line);
	if (i)
	{
		(*six)++;
		add_image_data(data, line, i);
	}
	else
		free(line);
	return (i);
}

void	get_six_points(t_data *data, int fd)
{
	char	*line;
	int		six;

	six = 0;
	line = get_next_line(fd);
	while (line && is_intel(data, line, &six))
	{
		free(line);
		if (six == 6)
			break ;
		line = get_next_line(fd);
	}
	if (six < 6)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("missing texture or rgb before map", 2);
		data->fd = fd;
		free_data(&data);
		exit (1);
	}
}

void	get_map_intel(t_data *data, char *s)
{
	int		fd;
	char	*line;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		free_data(&data);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("invalid file descriptor", 2);
		free_data(&data);
		exit(1);
	}
	data->fd = fd;
	get_six_points(data, fd);
	line = gnl_skip(data);
	get_tab_intel(data, fd, line);
}
