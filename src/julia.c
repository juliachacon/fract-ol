/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:40:59 by julia             #+#    #+#             */
/*   Updated: 2025/11/15 17:45:59 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(t_fractal *fractal)
{
	int		i;
	double	tmp;
	double	zx;
	double	zy;
	double	cx;
	double	cy;

	cx = fractal->cx;// Const c fijada al iniciaro con J
	cy = fractal->cy;

	// Punto inicial z0 = punto del plano correspondiente al píxel (x, y)
	zx = ((fractal->x - SIZE / 2.0) / fractal->zoom) + fractal->offset_x;
	zy = ((fractal->y - SIZE / 2.0) / fractal->zoom) + fractal->offset_y;

	i = 0;
	while (i < fractal->max_iterations)
	{
		tmp = zx;
		zx = zx * zx - zy * zy + cx;
		zy = 2 * zy * tmp + cy;
		if (zx * zx + zy * zy >= 4)
			break ;
		i++;
	}
    put_color_to_pixel(fractal, fractal->x, fractal->y, get_color(fractal, i));
}

//alternativa a blancos//grises
// 	if (i == fractal->max_iterations)
// 		put_color_to_pixel(fractal, fractal->x, fractal->y, 0xFFFFFF);
// 	else
// 	{
// 		double	t;
// 		int		shade;
// 		int		color;

// 		t = (double)i / fractal->max_iterations;
// 		shade = (int)(255 * (1.0 - t));
// 		color = (shade << 16) | (shade << 8) | shade;
// 		put_color_to_pixel(fractal, fractal->x, fractal->y, color);
// 	}
// }