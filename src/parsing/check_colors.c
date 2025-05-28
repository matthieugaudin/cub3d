/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 09:06:20 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/26 14:00:23 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	atoi_spe(char *s)
{
	int	nb;

	nb = 0;
	while (*s && *s == 32)
		s++;
	if (!ft_isdigit(*s))
		return (-1);
	while (ft_isdigit(*s))
	{
		nb = nb * 10 + (*s - '0');
		s++;
		if (nb > 255)
			return (-1);
	}
	return (nb);
}

void	colors_error(t_data *data)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("atleast one rgb is invalid", 2);
	free_data(&data);
	exit(0);
}

void	valid_colors(char *s, t_data *data)
{
	int	i;

	i = 0;
	while (i < 3 && *s)
	{
		if (atoi_spe(s) == -1)
			colors_error(data);
		while (*s && *s == 32)
			s++;
		while (ft_isdigit(*s))
			s++;
		while (*s && *s == 32)
			s++;
		i++;
		if (*s && *s != ',')
			colors_error(data);
		if (*s)
			s++;
	}
	if (i < 3)
		colors_error(data);
	while (*s && *s == 32)
		s++;
	if (*s)
		colors_error(data);
}

int	get_colors(char *s)
{
	int	r;
	int	g;
	int	b;

	r = atoi_spe(s);
	skip_space(&s);
	while (ft_isdigit(*s))
		s++;
	skip_space(&s);
	while (*s && *s == 32)
		s++;
	skip_space(&s);
	s++;
	g = atoi_spe(s);
	skip_space(&s);
	while (ft_isdigit(*s))
		s++;
	skip_space(&s);
	s++;
	b = atoi_spe(s);
	return ((r << 16) | (g << 8) | b);
}

void	check_colors(t_data *data)
{
	valid_colors(data->c_color, data);
	valid_colors(data->f_color, data);
	data->c_hex = get_colors(data->c_color);
	data->f_hex = get_colors(data->f_color);
}
