/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bship.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:50:33 by julia             #+#    #+#             */
/*   Updated: 2025/11/15 17:51:25 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_ship(t_fractal *fractal, int i)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		color;

	if (i == fractal->max_iterations)
	{
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
		return ;
	}
	t = (double)i / fractal->max_iterations;
	r = (int)(((fractal->color >> 16) & 0xFF) * t);
	g = (int)(((fractal->color >> 8) & 0xFF) * t);
	b = (int)((fractal->color & 0xFF) * t);
	color = (r << 16) | (g << 8) | b;
	put_color_to_pixel(fractal, fractal->x, fractal->y, color);
}

void	calculate_burning_ship(t_fractal *fractal)
{
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	tmp;
	int		i;

	cx = ((fractal->x - SIZE / 2.0) / fractal->zoom) + fractal->offset_x;
	cy = ((fractal->y - SIZE / 2.0) / fractal->zoom) + fractal->offset_y;
	zx = 0.0;
	zy = 0.0;
	i = 0;
	while (i < fractal->max_iterations)
	{
		zx = fabs(zx);
		zy = fabs(zy);
		tmp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = tmp;
		if (zx * zx + zy * zy >= 4.0)
			break ;
		i++;
	}
	color_ship(fractal, i);
}
