/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:24:18 by ndelhota          #+#    #+#             */
/*   Updated: 2025/04/30 16:07:37 by mgaudin          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CUBE3D_H
# define CUBE3D_H

# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/time.h>
# include <math.h>
# include <X11/X.h>
# include "mlx_linux/mlx.h"
# include "lib/libft/libft.h"
# include "lib/gnl/get_next_line.h"
# define PI 3.1415926535
# define WIDTH 1440
# define HEIGHT 810

typedef struct	s_data
{
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	char	*f_color;
	char	*c_color;
	char	**map;
	char	**flood_map;
	size_t	map_width;
	size_t	map_length;
	int	starting_point;
	int	fd;
	uint64_t	checkstart;
	char	*map_name;
	struct t_mlx_env	*mlx;
}	t_data;

enum e_keys
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
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
	t_data	*data;
	int		x;
	int		y;
}	t_mlx_env;


//map_generation
void	gen_map(t_data *data, char *map_name);
void	get_map_intel(t_data *data, char *s);
void	add_image_data(t_data *data, char *line, int mode);
char	*gnl_skip(t_data *data);
void	check_alloc(char *to_check, t_data *data, char *to_free);
void	get_map(t_data *data, char *map_name);
void	flood_fill(t_data *data);
void	check_map_border(t_data *data, char **map);
int	check_all(char *line);

//map_gen_error
void	empty_texture_reference(char *line, t_data *data);
void	invalid_reference(t_data *data);
void	failed_malloc(t_data *data);
void	multiple_start(t_data *data, char *line);
void	invalid_char(t_data *data, char *line);
void	void_in_map(t_data *data);
void	no_start(t_data *data);
void	unclosed_map(t_data *data);
void	splitted_map(t_data *data);

// ray casting
void    init_env(t_mlx_env *env);
void	handle_events(t_mlx_env *env);
void	draw_window(t_mlx_env *env);
void	draw_player(t_mlx_env *env, int player_size);
void	draw_line(t_mlx_env *env, int xa, int ya, int xb, int yb);
void	put_pixel(t_img *img, int x, int y, int color);

// memory managment
void	free_data(t_data **data);
#endif
