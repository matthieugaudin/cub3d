/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:32:10 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/19 14:54:44 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	valid_point(int x, int y)
{
	if (x < 0 || x > WIDTH)
		return (0);
	if (y < 0 || y > HEIGHT)
		return (0);
	return (1);
}

void	draw_point(t_mlx_env *env, int x, int y, t_racaster *ray)
{
	int	map_x;
	int	map_y;

	map_x = env->data->map_length * (y) / HEIGHT;
	map_y = env->data->map_width * (x) / WIDTH;
	if (map_x < 0 || map_y < 0)
		return ;
	if (map_x > (int)env->data->map_length - 1
		|| map_y > (int)env->data->map_width - 1)
		return ;
	if (env->data->map[map_x][map_y] == '1')
		put_pixel(&env->map, x - ray->pixel_x + 152,
			ray->pixel_y - y + 152, 0x000000);
	else
		put_pixel(&env->map, x - ray->pixel_x + 152,
			ray->pixel_y - y + 152, 0xffffff);
}

void	draw_map_wall(t_mlx_env *env, t_racaster *ray)
{
	int	x;
	int	y;

	x = ray->pixel_x - 150;
	while (x < (ray->pixel_x + 150))
	{
		y = (ray->pixel_y + 150);
		while (y > (ray->pixel_y - 150))
		{
			if (valid_point(x, y))
				draw_point(env, x, y, ray);
			else
				put_pixel(&env->map, x - ray->pixel_x + 152,
					ray->pixel_y - y + 152, 0x4169E1);
			y--;
		}
		x++;
	}
}

void	draw_map(t_mlx_env *env, t_racaster *ray)
{
	if (HEIGHT < 320 || WIDTH < 320)
		return ;
	ray->pixel_x = ray->pos_y * WIDTH / env->data->map_width;
	ray->pixel_y = ray->pos_x * HEIGHT / env->data->map_length;
	draw_map_wall(env, ray);
	mlx_put_image_to_window(env->mlx, env->win, env->map.img,
		WIDTH - 320, HEIGHT - 320);
}
