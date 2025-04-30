/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:54:40 by ndelhota          #+#    #+#             */
/*   Updated: 2025/04/28 12:48:02 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	free_char(char *s)
{
	if (s)
	{
		free(s);
	}
}

void	free_tab(char **s)
{
	char	**to_free;

	if (!s)
		return ;
	to_free = s;	
	while (*s)
	{
		printf("%s\n", *s);
		free(*s);
		s++;
	}
	free(to_free);
}

void	gnl_trap(t_data *data)
{
	char	*line;

	line = get_next_line(data->fd);
	while (line)
	{
		free(line);
		line = get_next_line(data->fd);
	}
	close(data->fd);
}

void	free_data(t_data **data)
{
	if (*data)
	{
		if ((*data)->fd)
			gnl_trap(*data);
		free_char((*data)->n_texture);
		free_char((*data)->s_texture);
		free_char((*data)->w_texture);
		free_char((*data)->e_texture);
		free_char((*data)->f_color);
		free_char((*data)->c_color);
		free((*data)->map_name);
		free_tab((*data)->map);
		printf("flood_map\n");
		free_tab((*data)->flood_map);
		free(*data);
		*data = NULL;
	}

}
