/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:35:14 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/25 11:48:46 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	empty_texture_reference(char *line, t_data *data)
{
	free(line);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("empty content for a color or a texture", 2);
	free_data(&data);
	exit (0);
}

void	failed_malloc(t_data *data)
{
	perror("error");
	free_data(&data);
	exit (1);
}

void	invalid_reference(t_data *data)
{
	free_data(&data);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("one or more needed references are missing", 2);
	exit (1);
}

void	multiple_start(t_data *data, char *line)
{
	free(line);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("too many starting points", 2);
	free_data(&data);
	exit (0);
}

void	invalid_char(t_data *data, char *line)
{
	free(line);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("invalid character in map", 2);
	free_data(&data);
	exit (0);
}
