/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:27:18 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/26 13:54:18 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	*gnl_skip(t_data *data)
{
	char	*line;

	line = get_next_line(data->fd);
	while (line && ft_strlen(line) == 1)
	{
		free(line);
		line = get_next_line(data->fd);
	}
	if (!line)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("no map datas", 2);
		free_data(&data);
		exit(0);
	}
	return (line);
}

char	*ft_spestr(t_data *data, char *line, char *place)
{
	char	*cursor;
	int		i;
	char	*to_ret;

	check_alloc(place, data, line);
	cursor = line;
	skip_space(&cursor);
	if (*cursor == 'C' || *cursor == 'F')
		cursor++;
	else
		cursor += 2;
	while (*cursor && *cursor == 32)
		cursor++;
	i = ft_strlen(cursor);
	if (i <= 1)
		empty_texture_reference(line, data);
	to_ret = ft_substr(cursor, 0, i - 1);
	if (!to_ret)
	{
		free(line);
		failed_malloc(data);
	}
	return (to_ret);
}

void	check_alloc(char *to_check, t_data *data, char *to_free)
{
	if (to_check)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("double reference to the same element", 2);
		free(to_free);
		free_data(&data);
		exit (0);
	}
}

int	check_all(char *s)
{
	skip_space(&s);
	if (!ft_strncmp(s, "NO ", 3))
		return (1);
	if (!ft_strncmp(s, "SO ", 3))
		return (2);
	if (!ft_strncmp(s, "WE ", 3))
		return (3);
	if (!ft_strncmp(s, "EA ", 3))
		return (4);
	if (!ft_strncmp(s, "F ", 2) || (*s == 'F' && ft_isalnum(*(s + 1))))
		return (5);
	if (!ft_strncmp(s, "C ", 2) || (*s == 'C' && ft_isalnum((*s + 1))))
		return (6);
	return (0);
}

void	add_image_data(t_data *data, char *line, int mode)
{
	if (mode == 1)
		data->n_texture = ft_spestr(data, line, data->n_texture);
	if (mode == 2)
		data->s_texture = ft_spestr(data, line, data->s_texture);
	if (mode == 3)
		data->w_texture = ft_spestr(data, line, data->w_texture);
	if (mode == 4)
		data->e_texture = ft_spestr(data, line, data->e_texture);
	if (mode == 5)
		data->f_color = ft_spestr(data, line, data->f_color);
	if (mode == 6)
		data->c_color = ft_spestr(data, line, data->c_color);
}
