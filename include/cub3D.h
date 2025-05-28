/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 08:24:18 by ndelhota          #+#    #+#             */
/*   Updated: 2025/05/27 09:26:25 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/time.h>
# include <math.h>
# include <X11/X.h>
# include <stdbool.h>
# include "../lib/mlx_linux/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# define PI 3.14159265358979323846
# define WIDTH 1920
# define HEIGHT 880

typedef struct s_data
{
	char				*n_texture;
	char				*s_texture;
	char				*w_texture;
	char				*e_texture;
	char				*f_color;
	char				*c_color;
	char				**map;
	char				**flood_map;
	size_t				map_width;
	size_t				map_length;
	int					starting_point;
	int					fd;
	int					x_start;
	int					y_start;
	int					f_hex;
	int					c_hex;
	uint64_t			checkstart;
	char				*map_name;
	struct t_mlx_env	*mlx;
}	t_data;

enum e_keys
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_M = 109
};

typedef struct s_key
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	esc;
	bool	left;
	bool	right;
	bool	m;
}	t_key;

typedef struct s_img
{
	void	*img;
	char	*pixel;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		length;
}	t_img;

typedef struct s_racaster
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		step_x;
	int		step_y;
	int		pixel_x;
	int		pixel_y;
	int		map_x;
	int		map_y;
	int		side;
}	t_racaster;

typedef struct s_mlx_env
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		north;
	t_img		west;
	t_img		east;
	t_img		south;
	t_img		map;
	t_data		*data;
	t_key		keys;
	t_racaster	ray;
	bool		angle_flag;
	int			last_x;
	int			text_num;
	int			*texture[4];
}	t_mlx_env;

// map generation
void	gen_map(t_data *data, char *map_name);
void	get_map_intel(t_data *data, char *s);
void	add_image_data(t_data *data, char *line, int mode);
char	*gnl_skip(t_data *data);
void	check_alloc(char *to_check, t_data *data, char *to_free);
void	get_map(t_data *data, char *map_name);
void	flood_fill(t_data *data);
void	check_colors(t_data *data);
void	check_map_border(t_data *data, char **map);
void	skip_space(char **s);
void	map_end(t_data *data, char *line);
int		check_all(char *line);

// map generation errors
void	empty_texture_reference(char *line, t_data *data);
void	invalid_reference(t_data *data);
void	failed_malloc(t_data *data);
void	multiple_start(t_data *data, char *line);
void	invalid_char(t_data *data, char *line);
void	void_in_map(t_data *data);
void	no_start(t_data *data);
void	unclosed_map(t_data *data);
void	splitted_map(t_data *data);
int		check_cross(char **map, int j, int i);

// event handling
int		handle_mouse(int x, int y, t_mlx_env *env);
int		handle_key_press(int keypress, t_mlx_env *env);
int		handle_key_release(int keycode, t_mlx_env *env);

// game rendering
int		game_loop(t_mlx_env *env);
void	init_env(t_mlx_env *env);
void	nullify_texture(t_mlx_env *env);
void	init_minimap(t_mlx_env *env);
void	init_texture(t_mlx_env *env);
void	handle_events(t_mlx_env *env);
void	put_pixel(t_img *img, int x, int y, int color);
void	check_events(t_mlx_env *env, t_racaster *ray);
void	draw_ray(t_mlx_env *env, t_racaster *ray, int x);
void	draw_map(t_mlx_env *env, t_racaster *ray);
void	rotate(t_racaster *ray, double rote);

// memory managment
void	destroy_all(t_mlx_env *env);
void	trim_texture(char **s);
void	close_texture(t_mlx_env	*env);
void	free_data(t_data **data);
void	gnl_trap(t_data *data);

#endif /* CUB3D_H */
