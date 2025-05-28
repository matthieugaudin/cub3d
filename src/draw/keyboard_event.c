/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:27:40 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/19 12:28:10 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	change_m(t_mlx_env *env)
{
	if (env->keys.m == true)
		env->keys.m = false;
	else
		env->keys.m = true;
}

int	handle_key_press(int keycode, t_mlx_env *env)
{
	if (keycode == KEY_W)
		env->keys.w = true;
	else if (keycode == KEY_A)
		env->keys.a = true;
	else if (keycode == KEY_S)
		env->keys.s = true;
	else if (keycode == KEY_D)
		env->keys.d = true;
	else if (keycode == KEY_RIGHT)
		env->keys.right = true;
	else if (keycode == KEY_LEFT)
		env->keys.left = true;
	else if (keycode == KEY_M)
		change_m(env);
	else if (keycode == 65307)
		destroy_all(env);
	return (0);
}

int	handle_key_release(int keycode, t_mlx_env *env)
{
	if (keycode == KEY_W)
		env->keys.w = false;
	else if (keycode == KEY_A)
		env->keys.a = false;
	else if (keycode == KEY_S)
		env->keys.s = false;
	else if (keycode == KEY_D)
		env->keys.d = false;
	else if (keycode == KEY_ESC)
		env->keys.esc = false;
	else if (keycode == KEY_RIGHT)
		env->keys.right = false;
	else if (keycode == KEY_LEFT)
		env->keys.left = false;
	return (0);
}
