/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:53:01 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/19 12:13:15 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	rotate(t_racaster *ray, double rota)
{
	double	old_dir;
	double	old_plane;
	double	c_cos;
	double	c_sin;

	c_sin = sin(rota);
	c_cos = cos(rota);
	old_dir = ray->dir_x;
	old_plane = ray->plane_x;
	ray->dir_x = ray->dir_x * c_cos - ray->dir_y * c_sin;
	ray->dir_y = old_dir * c_sin + ray->dir_y * c_cos;
	ray->plane_x = ray->plane_x * c_cos - ray->plane_y * c_sin;
	ray->plane_y = old_plane * c_sin + ray->plane_y * c_cos;
}
