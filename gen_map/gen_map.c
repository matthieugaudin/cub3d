/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:32:09 by ndelhota          #+#    #+#             */
/*   Updated: 2025/04/23 11:02:37 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	check_open(t_data *data, char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		free_data(&data);
		perror("error");
		exit(0);
	}
	data->map_name = ft_strdup(s);
	close(fd);
}
void	check_name(t_data *data, char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	if (i < 5 || ft_strncmp((s - 4), ".cub", 4))
	{
		free_data(&data);
		ft_putendl_fd("error : invalid_map_name", 2);
		exit (0);
	}
}

void	gen_map(t_data *data, char *map_name)
{
	check_name(data, map_name);
	check_open(data, map_name);
	get_map_intel(data, map_name);
}
