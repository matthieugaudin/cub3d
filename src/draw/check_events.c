/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:00:52 by mgaudin           #+#    #+#             */
/*   Updated: 2025/05/25 11:19:04 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	d_press(t_mlx_env *env, t_racaster *ray)
{
	int	x_move;
	int	y_move;

	x_move = 0;
	y_move = 0;
	if (env->data->map[(int)(ray->pos_x + ray->dir_y * ray->move_speed)]
		[(int)ray->pos_y] != '1')
		x_move = 1;
	if (env->data->map[(int)ray->pos_x]
		[(int)(ray->pos_y - ray->dir_x * ray->move_speed)] != '1')
		y_move = 1;
	if (y_move)
		ray->pos_y -= ray->dir_x * ray->move_speed;
	if (x_move)
		ray->pos_x += ray->dir_y * ray->move_speed;
}

void	a_press(t_mlx_env *env, t_racaster *ray)
{
	int	x_move;
	int	y_move;

	x_move = 0;
	y_move = 0;
	if (env->data->map[(int)(ray->pos_x - ray->dir_y * ray->move_speed)]
		[(int)ray->pos_y] != '1')
		x_move = 1;
	if (env->data->map[(int)ray->pos_x]
		[(int)(ray->pos_y + ray->dir_x * ray->move_speed)] != '1')
		y_move = 1;
	if (x_move)
		ray->pos_x -= ray->dir_y * ray->move_speed;
	if (y_move)
		ray->pos_y += ray->dir_x * ray->move_speed;
}

void	s_press(t_mlx_env *env, t_racaster *ray)
{
	int	x_move;
	int	y_move;

	x_move = 0;
	y_move = 0;
	if (env->data->map[(int)(ray->pos_x - ray->dir_x * ray->move_speed)]
		[(int)ray->pos_y] != '1')
		x_move = 1;
	if (env->data->map[(int)ray->pos_x]
		[(int)(ray->pos_y - ray->dir_y * ray->move_speed)] != '1')
		y_move = 1;
	if (y_move)
		ray->pos_y -= ray->dir_y * ray->move_speed;
	if (x_move)
		ray->pos_x -= ray->dir_x * ray->move_speed;
}

void	w_press(t_mlx_env *env, t_racaster *ray)
{
	int	x_move;
	int	y_move;

	x_move = 0;
	y_move = 0;
	if (env->data->map[(int)(ray->pos_x + ray->dir_x * ray->move_speed)]
		[(int)ray->pos_y] != '1')
		x_move = 1;
	if (env->data->map[(int)ray->pos_x]
		[(int)(ray->pos_y + ray->dir_y * ray->move_speed)] != '1')
		y_move = 1;
	if (y_move)
		ray->pos_y += ray->dir_y * ray->move_speed;
	if (x_move)
		ray->pos_x += ray->dir_x * ray->move_speed;
}

void	check_events(t_mlx_env *env, t_racaster *ray)
{
	if (env->keys.w)
		w_press(env, ray);
	if (env->keys.s)
		s_press(env, ray);
	if (env->keys.a)
		a_press(env, ray);
	if (env->keys.d)
		d_press(env, ray);
	if (env->keys.right)
		rotate(ray, -ray->rot_speed);
	if (env->keys.left)
		rotate(ray, ray->rot_speed);
}
