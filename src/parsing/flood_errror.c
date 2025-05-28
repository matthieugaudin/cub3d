/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_errror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:20:31 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/25 11:50:44 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	unclosed_map(t_data *data)
{
	free_data(&data);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("unclosed map", 2);
	exit (0);
}

void	void_in_map(t_data *data)
{
	free_data(&data);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("void space in the map", 2);
	exit (0);
}

void	no_start(t_data *data)
{
	free_data(&data);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("starting point is missing", 2);
	exit (0);
}

void	splitted_map(t_data *data)
{
	free_data(&data);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("map is splitted", 2);
	exit (0);
}
