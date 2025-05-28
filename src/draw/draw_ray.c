/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:07:25 by mgaudin           #+#    #+#             */
/*   Updated: 2025/05/25 11:17:21 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	get_color(t_mlx_env *env, t_img *texture, int tex_x, int tex_y)
{
	int	color;
	int	num;

	num = env->text_num;
	color = env->texture[num][texture->length * tex_y + tex_x];
	return (color);
}

void	draw_wall_ray(t_mlx_env *env, t_img *texture, t_racaster *ray, int x)
{
	double	wall_x;
	double	tex_pos;
	double	step;
	int		tex_x;
	int		tex_y;

	if (ray->side == 0)
		wall_x = ray->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = ray->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * texture->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = texture->width - tex_x - 1;
	step = 1.0 * texture->length / ray->line_height;
	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * step;
	while (ray->draw_start <= ray->draw_end)
	{
		tex_y = (int)tex_pos & (texture->length - 1);
		tex_pos += step;
		put_pixel(&env->img, x, ray->draw_start,
			get_color(env, texture, tex_x, tex_y));
		ray->draw_start++;
	}
}

void	set_texture(t_mlx_env *env, t_racaster *ray, t_img **texture)
{
	if (ray->side == 1 && ray->ray_dir_y > 0)
	{
		*texture = &env->east;
		env->text_num = 3;
	}
	else if (ray->side == 1 && ray->ray_dir_y < 0)
	{
		*texture = &env->west;
		env->text_num = 2;
	}
	if (ray->side == 0 && ray->ray_dir_x > 0)
	{
		*texture = &env->south;
		env->text_num = 1;
	}
	else if (ray->side == 0 && ray->ray_dir_x < 0)
	{
		*texture = &env->north;
		env->text_num = 0;
	}
}

void	draw_ray(t_mlx_env *env, t_racaster *ray, int x)
{
	t_img	*texture;
	int		i;

	i = 0;
	while (i < ray->draw_start)
	{
		put_pixel(&env->img, x, i, env->data->c_hex);
		i++;
	}
	set_texture(env, &env->ray, &texture);
	draw_wall_ray(env, texture, &env->ray, x);
	i = ray->draw_start;
	while (i < HEIGHT)
	{
		put_pixel(&env->img, x, i, env->data->f_hex);
		i++;
	}
}
