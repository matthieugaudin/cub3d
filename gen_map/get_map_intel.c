/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_intel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:52:24 by ndelhota          #+#    #+#             */
/*   Updated: 2025/04/28 12:24:07 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

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
		if (ft_strlen(line) == 1)
			invalid_char(data, line);
		parse_count_line(data, line);
		free(line);
		line = get_next_line(fd);
		length++;
	}
	data->map_length = length;
	printf("lenght : %d\n", length);
}

int	is_intel(t_data *data, char *line, int *six)
{
	int	i;

	if (ft_strlen(line) == 1 && *line == '\n')
		return (1);
	i = check_all(line);
	if (i)
	{
		(*six)++;
		add_image_data(data, line, i);
	}
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
}

void	get_map_intel(t_data *data, char *s)
{
	int		fd;
	char	*line;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		free_data(&data);
		perror("error");
		exit(1);
	}
	data->fd = fd;
	get_six_points(data, fd);
	line = gnl_skip(data);
	get_tab_intel(data, fd, line);
	printf("width: %zu\n", data->map_width);
}
