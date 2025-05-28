/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:35:02 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/25 11:09:45 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	fill_column(int x, int y, t_mlx_env *env)
{
	while (y < 305)
	{
		put_pixel(&env->map, x, y, 0X00FF00);
		y++;
	}
}

void	fill_line(int x, int y, t_mlx_env *env)
{
	while (x < 305)
	{
		put_pixel(&env->map, x, y, 0x00FF00);
		x++;
	}
}

void	init_minimap(t_mlx_env *env)
{
	env->keys.m = false;
	env->map.img = mlx_new_image(env->mlx, 305, 305);
	if (!env->map.img)
		destroy_all(env);
	env->map.pixel = mlx_get_data_addr(env->map.img, &env->map.bpp,
			&env->map.line_len, &env->map.endian);
	fill_line(0, 0, env);
	fill_line(0, 304, env);
	fill_column(0, 0, env);
	fill_column(304, 0, env);
}
