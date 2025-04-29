/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_intel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:52:24 by ndelhota          #+#    #+#             */
/*   Updated: 2025/04/23 12:00:51 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	get_six_points(t_data *data, int fd)
{
	char	*line;
	int	six;

	six = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	data = NULL;
}

void	get_map_intel(t_data *data, char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	get_six_points(data, fd);
	close(fd);

}
