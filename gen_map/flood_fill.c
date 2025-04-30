/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:34:17 by ndelhota          #+#    #+#             */
/*   Updated: 2025/04/28 15:17:37 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	check_map(t_data *data, char **s)
{
	char	*cursor;

	while (*s)
	{
		cursor = *s;
		while (*cursor)
		{
			if (*cursor != '1' && *cursor != 'X')
				splitted_map(data);
			cursor++;
		}
		s++;
	}
}

void	flood_filling(t_data *data, char **map, int x, int y)
{
	if (x < 0|| y < 0)
		return ;
	if ((unsigned long)x > data->map_length - 1
		|| (unsigned long)y > data->map_width - 1)
		return ;
	if (map[x][y] == '1')
		return ;
	if (map[x][y] == 'X')
		void_in_map(data);
	map[x][y] = '1';
	flood_filling(data, map, x + 1, y);
	flood_filling(data, map, x - 1, y);
	flood_filling(data, map, x, y + 1);
	flood_filling(data, map, x, y - 1);
}

void	find_start(t_data *data, int *i, int *y, char **s)
{
	while (*s)
	{
		*i = 0;
		while(s[0][*i])
		{
			if (s[0][*i] == 'W' || s[0][*i] == 'N' || s[0][*i] == 'E'
				|| s[0][*i] == 'S')
				return;
			(*i)++;
		}
		s++;
		(*y)++;
	}
	no_start(data);
}

void	dup_map(t_data *data)
{
	int	i;

	i = 0;
	data->flood_map =  ft_calloc(sizeof(char *), (data->map_length + 1));
	while(data->map[i])
	{
		data->flood_map[i] = ft_strdup(data->map[i]);
		i++;
	}	
}

void	flood_fill(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	dup_map(data);
	find_start(data, &y, &x, data->map);
	flood_filling(data, data->flood_map, x, y);
	check_map(data, data->flood_map);
	check_map_border(data, data->flood_map);
}
