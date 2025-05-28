/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 08:04:18 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/26 13:46:11 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	close_texture(t_mlx_env *env)
{
	if (env->north.img)
		mlx_destroy_image(env->mlx, env->north.img);
	if (env->west.img)
		mlx_destroy_image(env->mlx, env->west.img);
	if (env->east.img)
		mlx_destroy_image(env->mlx, env->east.img);
	if (env->south.img)
		mlx_destroy_image(env->mlx, env->south.img);
}

void	texture_error(t_mlx_env *env, int num)
{
	num--;
	while (num >= 0)
	{
		free(env->texture[num]);
		env->texture[num] = NULL;
		num--;
	}
	destroy_all(env);
}

void	init_texture_buffer(t_mlx_env *env, t_img *img, int num)
{
	int	x;
	int	y;

	env->texture[num] = malloc(sizeof(int) * img->width * img->length);
	if (!env->texture[num])
		texture_error(env, num);
	y = 0;
	while (y < img->length)
	{
		x = 0;
		while (x < img->width)
		{
			env->texture[num][y * img->length + x]
				= ((int *)img->pixel)[y * (img->line_len / 4) + x];
			x++;
		}
		y++;
	}
}

void	open_texture(t_img *img, char *pathname, t_mlx_env *env, int num)
{
	img->img = mlx_xpm_file_to_image(env->mlx, pathname,
			&img->width, &img->length);
	if (!img->img)
	{
		ft_putendl_fd("Error", 2);
		ft_putstr_fd(pathname, 2);
		ft_putstr_fd(" is invalid or cant be openned\n", 2);
		destroy_all(env);
	}
	img->pixel = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	init_texture_buffer(env, img, num);
}

void	init_texture(t_mlx_env *env)
{
	trim_texture(&env->data->n_texture);
	trim_texture(&env->data->s_texture);
	trim_texture(&env->data->w_texture);
	trim_texture(&env->data->e_texture);
	open_texture(&env->north, env->data->n_texture, env, 0);
	open_texture(&env->south, env->data->s_texture, env, 1);
	open_texture(&env->west, env->data->w_texture, env, 2);
	open_texture(&env->east, env->data->e_texture, env, 3);
}
