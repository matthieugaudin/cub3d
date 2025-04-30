/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_errror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:20:31 by ndelhota          #+#    #+#             */
/*   Updated: 2025/04/28 15:26:14 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	unclosed_map(t_data *data)
{
	free_data(&data);
	ft_putendl_fd("error : unclosed map", 2);
	exit (0);
}

void	void_in_map(t_data *data)
{
	free_data(&data);
	ft_putendl_fd("error : void space in the map", 2);
	exit (0);
}

void	no_start(t_data *data)
{
	free_data(&data);
	ft_putendl_fd("error : starting point is missing", 2);
	exit (0);
}

void	splitted_map(t_data *data)
{
	free_data(&data);
	ft_putendl_fd("error : map is splitted", 2);
	exit (0);
}
