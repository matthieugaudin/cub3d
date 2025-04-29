/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:31:31 by mgaudin           #+#    #+#             */
/*   Updated: 2025/04/29 10:57:54 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
# include "mlx_linux/mlx.h"
# include <X11/X.h>
# include <stdbool.h>
# define WIDTH 1440
# define HEIGHT 810
# define PI 3.1415926535

enum e_keys
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363
};

typedef struct s_img
{
	void	*img;
	char	*pixel;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		player_size;
	double	pos_x;
	double	pos_y;
	double	delta_x;
	double	delta_y;
	double	player_angle;
}	t_mlx_env;


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

void	draw_player(t_mlx_env *env, int x, int y)
{
	int	i;
	int	j;

	i = x - (env->player_size / 2);
	while (i < x + (env->player_size / 2))
	{
		j = y - (env->player_size / 2);
		while (j < y + (env->player_size / 2))
		{
			ft_mlx_pixel_put(&env->img, i, j, 0x00ff00);
			j++;
		}
		i++;
	}
}

void	draw_game(t_mlx_env *env)
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;

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
	draw_player(env, env->pos_x, env->pos_y);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
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
		env->pos_y -= env->player_size;
	else if (keycode == KEY_A)
		env->pos_x -= env->player_size;
	else if (keycode == KEY_S)
		env->pos_y += env->player_size;
	else if (keycode == KEY_D)
		env->pos_x += env->player_size;
	else if (keycode == KEY_LEFT)
	{
		env->player_angle -= -0.1;
		if (env->player_angle < 0)
			env->player_angle += 2 * PI; 
		env->delta_x = cos(env->player_angle) * 5;
		env->delta_y = sin(env->player_angle) * 5;
	}
	else if (keycode == KEY_RIGHT)
	{
		env->player_angle += -0.1;
		if (env->player_angle > 2 * PI)
			env->player_angle -= 2 * PI; 
		env->delta_x = cos(env->player_angle) * 5;
		env->delta_y = sin(env->player_angle) * 5;
	}
	draw_game(env);
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
	env->pos_x = 22;
	env->pos_y = 460;
	env->player_size = 10;
	env->player_angle = 0;
	env->delta_x = cos(env->player_angle) * 5;
	env->delta_y = sin(env->player_angle) * 5;
}

void	handle_events(t_mlx_env *env)
{
	mlx_hook(env->win, KeyPress, KeyPressMask, handle_key_press, env);
	mlx_hook(env->win, DestroyNotify, StructureNotifyMask,
		handle_window, env);
}

int main(void)
{
    t_mlx_env   env;

    init_env(&env);
	draw_game(&env);
    handle_events(&env);
    mlx_loop(env.mlx);
}
