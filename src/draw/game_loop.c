/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:24:18 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/25 11:11:26 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	set_ray_data(t_racaster *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)(ray->pos_x);
	ray->map_y = (int)(ray->pos_y);
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	calc_step_side_dist(t_racaster *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
	}
}

static void	perform_dda(t_racaster *ray, t_mlx_env *env)
{
	bool	hit;

	hit = false;
	if (env->data->map[ray->map_x][ray->map_y] == '1')
	{
		env->angle_flag = true;
		return ;
	}
	while (!hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (env->data->map[ray->map_x][ray->map_y] == '1')
			hit = true;
	}
}

static void	calc_dist_height(t_racaster *ray, t_mlx_env *env)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	if (env->angle_flag)
	{
		ray->perp_wall_dist = 0.01;
		env->angle_flag = false;
	}
	if (fabs(ray->perp_wall_dist) < 1e-6)
		ray->perp_wall_dist = 0.008;
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

int	game_loop(t_mlx_env *env)
{
	int	x;

	check_events(env, &env->ray);
	x = 0;
	while (x < WIDTH)
	{
		set_ray_data(&env->ray, x);
		calc_step_side_dist(&env->ray);
		perform_dda(&env->ray, env);
		calc_dist_height(&env->ray, env);
		draw_ray(env, &env->ray, x);
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	if (env->keys.m == true)
		draw_map(env, &env->ray);
	return (0);
}
