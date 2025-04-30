/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:49:47 by ndelhota          #+#    #+#             */
/*   Updated: 2025/04/30 12:48:40 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	destroy_all(t_mlx_env *one)
{
	mlx_destroy_image(one->mlx, one->img);
	mlx_destroy_window(one->mlx, one->win);
	mlx_destroy_display(one->mlx);
	free(one->mlx);
	free_data(&one->data);
}

int	close_window_crux(void *param)
{
	t_mlx_env	*one;

	one = (t_mlx_env *)param;
	destroy_all(one);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_mlx_env *one)
{
	if (keycode == 65307)
	{
		destroy_all(one);
		exit (0);
	}
	return (0);
}

void	ft_graphic(t_data *data)
{
	t_mlx_env	one;

	one.mlx = mlx_init();
	one.data = data;
	one.win = mlx_new_window(one.mlx, 1920, 1080, "CUB3D");
	one.img = mlx_new_image(one.mlx, 1920, 1080);
	mlx_key_hook(one.win, &key_hook, &one);
	mlx_hook(one.win, 17, 0, close_window_crux, &one);
	mlx_loop(one.mlx);
}
