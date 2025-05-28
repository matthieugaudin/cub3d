/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:58:41 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/26 11:44:24 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	check_b_t(t_data *data, char *s)
{
	while (*s)
	{
		if (*s == '0')
			unclosed_map(data);
		s++;
	}
}

void	check_map_border(t_data *data, char **map)
{
	char	*cursor;

	cursor = *map;
	check_b_t(data, cursor);
	map++;
	while (*map && *(map + 1))
	{
		cursor = *map;
		if (*cursor == '0')
			unclosed_map(data);
		while (*(cursor + 1))
			cursor++;
		if (*cursor == '0')
			unclosed_map(data);
		map++;
	}
	cursor = *map;
	check_b_t(data, cursor);
}
