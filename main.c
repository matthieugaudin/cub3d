/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:43:49 by ndelhota          #+#    #+#             */
/*   Updated: 2025/04/24 10:08:29 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
	return (to_ret);
}

// int	main(int ac, char **argv)
// {
// 	t_data	*data;

// 	if (ac != 2)
// 	{
// 		ft_putendl_fd("invalid_args_number", 2);
// 		exit(0);
// 	}
// 	data = gen_data();
// 	gen_map(data, argv[1]);
// 	free_data(&data);
// }
