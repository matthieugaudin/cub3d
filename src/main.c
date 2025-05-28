/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:43:49 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/26 14:29:13 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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
	t_data		*data;
	t_mlx_env	env;

	if (ac != 2)
	{
		ft_putendl_fd("invalid_args_number", 2);
		exit(0);
	}
	data = gen_data();
	gen_map(data, argv[1]);
	env.data = data;
	init_env(&env);
	handle_events(&env);
	mlx_loop_hook(env.mlx, game_loop, &env);
	mlx_loop(env.mlx);
	free_data(&data);
}
