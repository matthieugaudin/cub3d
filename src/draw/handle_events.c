/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:17:38 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/25 11:18:26 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	destroy_all(t_mlx_env *env)
{
	free(env->texture[0]);
	free(env->texture[1]);
	free(env->texture[2]);
	free(env->texture[3]);
	close_texture(env);
	if (env->img.img)
		mlx_destroy_image(env->mlx, env->img.img);
	if (env->map.img)
		mlx_destroy_image(env->mlx, env->map.img);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->mlx)
		mlx_destroy_display(env->mlx);
	free(env->mlx);
	free_data(&env->data);
	exit(0);
}

int	close_crux(void *param)
{
	t_mlx_env	*env;

	env = (t_mlx_env *)param;
	destroy_all(env);
	return (0);
}

void	handle_events(t_mlx_env *env)
{
	mlx_hook(env->win, KeyPress, KeyPressMask, handle_key_press, env);
	mlx_hook(env->win, KeyRelease, KeyReleaseMask, handle_key_release, env);
	mlx_hook(env->win, DestroyNotify, NoEventMask, close_crux, env);
	mlx_hook(env->win, MotionNotify, PointerMotionMask, handle_mouse, env);
}
