/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:24:18 by ndelhota          #+#    #+#             */
/*   Updated: 2025/04/24 10:07:54 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/time.h>
# include <math.h>
# include "lib/libft/libft.h"
# include "lib/gnl/get_next_line.h"

typedef struct	s_data
{
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	char	*f_texture;
	char	*c_texture;
	int	**map;
	int	map_width;
	int	map_length;
	char	*map_name;

}	t_data;

//map_generation
void	gen_map(t_data *data, char *map_name);
void	get_map_intel(t_data *data, char *s);
//end
void	free_data(t_data **data);
#endif
