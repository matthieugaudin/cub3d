#include "cube3d.h"

static void	draw_line_heigh(t_mlx_env *env, int xa, int ya, int xb, int yb)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	x;
	int	i;

	xi = 1;
	dx = xb - xa;
	dy = yb - ya;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	x = xa;
	i = ya;
	while (i < yb + 1)
	{
		ft_mlx_pixel_put(&env->img, x, i, 0xff0000);
		if (d > 0)
		{
			x += xi;
			d += 2 * (dx - dy);
		}
		else
			d += 2 * dx;
	}
}

static void	draw_line_low(t_mlx_env *env, int xa, int ya, int xb, int yb)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	y;
	int	i;

	yi = 1;
	dx = xb - xa;
	dy = yb - ya;
	if (dx < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	y = ya;
	i = xa;
	while (i < xb + 1)
	{
		ft_mlx_pixel_put(&env->img, i, y, 0xff0000);
		if (d > 0)
		{
			y += yi;
			d += 2 * (dy - dx);
		}
		else
			d += 2 * dy;
	}
}

void	draw_line(t_mlx_env *env, int xa, int ya, int xb, int yb)
{
	if (abs(yb - ya) < abs(xb - xa))
	{
		if (xa > xb)
			draw_line_low(env, xb, yb, xa, ya);
		else
			draw_line_low(env, xa, ya, xb, yb);
	}
	else
	{
		if (ya > yb)
			draw_line_heigh(env, xb, yb, xa, ya);
		else
			draw_line_heigh(env, xa, ya, xb, yb);
	}
}
