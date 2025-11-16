/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:50:33 by julia             #+#    #+#             */
/*   Updated: 2025/11/16 17:04:38 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Loops through every pixel on the screen and calls calculate_mandelbrot()
** for each (x, y) coordinate to draw the full Mandelbrot fractal. */

void	draw_burning_ship(t_fractal *fractal)
{
	fractal->x = 0;
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			calculate_burning_ship(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
}

/*
** Computes the Burning Ship fractal for a single pixel.
**
** The Burning Ship fractal is defined similarly to the Mandelbrot set,
** but at each iteration both the real and imaginary parts of Z are
** replaced by their absolute values before applying:
**
**        Z(n+1) = Z(n)^2 + C
**
** Here, C is obtained from the pixel coordinates (x, y), and Z starts
** at 0. If the magnitude of Z grows beyond 2, the point is considered
** to escape and the iteration count determines its color via color_ship().
*/

void	calculate_burning_ship(t_fractal *fractal)
{
	double	zx;
	double	zy;
	double	tmp;
	int		i;

	zx = 0.0;
	zy = 0.0;
	i = 0;
	while (i < fractal->max_iterations)
	{
		zx = fabs(zx);
		zy = fabs(zy);
		tmp = zx * zx - zy * zy + ((fractal->x - SIZE / 2.0) / fractal->zoom
				+ fractal->offset_x);
		zy = 2 * zx * zy + ((fractal->y - SIZE / 2.0) / fractal->zoom
				+ fractal->offset_y);
		zx = tmp;
		if (zx * zx + zy * zy >= 4.0)
			break ;
		i++;
	}
	put_color_to_pixel(fractal, fractal->x, fractal->y, get_color(fractal, i));
}
