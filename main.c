/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:43:49 by ndelhota          #+#    #+#             */
/*   Updated: 2025/04/30 16:24:48 by mgaudin          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cube3d.h"

void	define_uint(uint64_t *checkstart)
{
	*checkstart |= 1ULL << ('W' - 'A');
	*checkstart |= 1ULL << ('S' - 'A');
	*checkstart |= 1ULL << ('N' - 'A');
	*checkstart |= 1ULL << ('E' - 'A');
}

t_data	*gen_data(void)
{
	t_data	*to_ret;

	to_ret = malloc(sizeof(t_data));
	if (!to_ret)
	{
		perror("error on first malloc");
		exit (1);
	}
	ft_memset(to_ret, 0, sizeof(t_data));
	define_uint(&to_ret->checkstart);
	return (to_ret);
}

int	main(int ac, char **argv)
{
	(void)ac;
	(void)argv;
	t_data		*data;
	t_mlx_env   env;

	if (ac != 2)
	{
		ft_putendl_fd("invalid_args_number", 2);
		exit(0);
	}
	data = gen_data();
	gen_map(data, argv[1]);
	init_env(&env);
	draw_window(&env);
	draw_player(&env, 10);
	draw_line(&env, env.x, env.y, env.x + 550, -HEIGHT);
	mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
	handle_events(&env);
	mlx_loop(env.mlx);
	free_data(&data);
}
