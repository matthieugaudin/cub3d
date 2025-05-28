/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 10:04:34 by mgaudin           #+#    #+#             */
/*   Updated: 2025/05/25 11:15:55 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	nullify_texture(t_mlx_env *env)
{
	env->north.img = NULL;
	env->south.img = NULL;
	env->west.img = NULL;
	env->east.img = NULL;
}

void	init_keys(t_mlx_env *env)
{
	env->keys.w = false;
	env->keys.a = false;
	env->keys.s = false;
	env->keys.d = false;
	env->keys.esc = false;
	env->keys.right = false;
	env->keys.left = false;
}

void	init_env_data(t_mlx_env *env)
{
	env->last_x = -1;
	env->angle_flag = false;
	env->ray.pos_x = env->data->y_start;
	env->ray.pos_y = env->data->x_start;
	env->ray.dir_x = -1;
	env->ray.dir_y = 0;
	env->ray.plane_x = 0;
	env->ray.plane_y = 0.66;
	env->ray.move_speed = 0.025;
	env->ray.rot_speed = 0.01;
	if (env->data->map[env->data->y_start][env->data->x_start] == 'S')
		rotate(&env->ray, PI);
	else if (env->data->map[env->data->y_start][env->data->x_start] == 'W')
		rotate(&env->ray, PI / 2);
	else if (env->data->map[env->data->y_start][env->data->x_start] == 'E')
		rotate(&env->ray, 3 * PI / 2);
}

void	init_env(t_mlx_env *env)
{
	env->mlx = NULL;
	env->win = NULL;
	env->img.img = NULL;
	env->map.img = NULL;
	env->texture[0] = NULL;
	env->texture[1] = NULL;
	env->texture[2] = NULL;
	env->texture[3] = NULL;
	nullify_texture(env);
	env->mlx = mlx_init();
	if (!env->mlx)
		destroy_all(env);
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "cub3D");
	if (!env->win)
		destroy_all(env);
	env->img.img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	if (!env->img.img)
		destroy_all(env);
	env->img.pixel = mlx_get_data_addr(env->img.img, &env->img.bpp,
			&env->img.line_len, &env->img.endian);
	init_env_data(env);
	init_keys(env);
	init_minimap(env);
	init_texture(env);
}
