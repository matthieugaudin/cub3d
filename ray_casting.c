/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:31:31 by mgaudin           #+#    #+#             */
/*   Updated: 2025/04/30 11:00:46 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
# define WIDTH 1440
# define HEIGHT 810

int	map[10][15] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};


void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pxl;
	int		offset;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		offset = (y * img->line_len) + (x * (img->bpp / 8));
		pxl = img->pixel + offset;
		*(unsigned int *)pxl = color;
	}
}

void	draw_window(t_mlx_env *env)
{
	int	x;
	int	y;
	int	map_x;
	int	map_y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			map_x = (10 * y) / HEIGHT;
			map_y = (15 * x) / WIDTH;
			if (map[map_x][map_y] == 1)
				ft_mlx_pixel_put(&env->img, x, y, 0xffffff);
			else
            	ft_mlx_pixel_put(&env->img, x, y, 0x0000);
			y++;
		}
		x++;
	}
}

void	draw_player(t_mlx_env *env, int player_size)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if ((env->x - (player_size / 2)) <= x && x <= (env->x + (player_size / 2))
				&& (env->y - (player_size / 2)) <= y && y <= (env->y + (player_size / 2)))
				ft_mlx_pixel_put(&env->img, x, y, 0x4cb817);
			y++;
		}
		x++;
	}
}

int	handle_mouse(int keycode, t_mlx_env *env)
{
	(void)keycode;
	(void)env;
	return (0);
	// to do
}

int	handle_window(int keycode, t_mlx_env *env)
{
	(void)keycode;
	(void)env;
	return (0);
	// to do
}

int	handle_key_press(int keycode, t_mlx_env *env)
{
	(void)env;

	if (keycode == KEY_W)
		env->y -= 10;
	if (keycode == KEY_A)
		env->x -= 10;
	if (keycode == KEY_S)
		env->y += 10;
	if (keycode == KEY_D)
		env->x += 10;
	draw_window(env);
	draw_player(env, 10);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}

void    init_env(t_mlx_env *env)
{
    env->mlx = mlx_init();
    if (!env->mlx)
        return ; // free
    env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "cub3D");
    if (!env->win)
        return ; // free
    env->img.img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
    if (!env->img.img)
        return ; // free
    env->img.pixel = mlx_get_data_addr(env->img.img, &env->img.bpp,
            &env->img.line_len, &env->img.endian);
	env->x = (WIDTH / 2);
	env->y = (HEIGHT / 2);
}

void	handle_events(t_mlx_env *env)
{
	mlx_mouse_hook(env->win, handle_mouse, env);
	mlx_hook(env->win, KeyPress, KeyPressMask, handle_key_press, env);
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask,
		handle_window, env);
}

 int main(void)
{
    t_mlx_env   env;

	init_env(&env);
	draw_window(&env);
	draw_player(&env, 10);
	mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
	handle_events(&env);
	mlx_loop(env.mlx);
}
