/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:03:47 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/25 11:10:11 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	mouse_rotate(t_mlx_env *env, int mode)
{
	if (mode > 0)
		rotate(&env->ray, env->ray.rot_speed);
	else
		rotate(&env->ray, -env->ray.rot_speed);
}

int	handle_mouse(int x, int y, t_mlx_env *env)
{
	int	treshold;

	treshold = HEIGHT / 10;
	y = 0;
	if (env && env->last_x == -1)
	{
		env->last_x = x;
		return (0);
	}
	if (x > env->last_x && x < env->last_x + 10)
		return (0);
	if (x < env->last_x && x > env->last_x - 10)
		return (0);
	mouse_rotate(env, env->last_x - x);
	env->last_x = x;
	if (env->last_x <= treshold || env->last_x >= WIDTH - treshold)
	{
		mlx_mouse_move(env->mlx, env->win, WIDTH / 2, HEIGHT / 2);
		env->last_x = WIDTH / 2;
	}
	return (0);
}
