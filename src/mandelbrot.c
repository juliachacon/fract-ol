/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:24:39 by julia             #+#    #+#             */
/*   Updated: 2025/11/15 17:47:17 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	fractal->name = "mandelbrot";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = ((fractal->x - SIZE / 2.0) / fractal->zoom) + fractal->offset_x;
	fractal->cy = ((fractal->y - SIZE / 2.0) / fractal->zoom) + fractal->offset_y;
	while (i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= 4)
			break ;
		i++;
	}

	put_color_to_pixel(fractal, fractal->x, fractal->y, get_color(fractal, i));
}

// 	if (i == fractal->max_iterations)
// 		put_color_to_pixel(fractal, fractal->x, fractal->y, 0xFFFFFF);
// 	else
// 	{
// 		// Puntos que escapan -> escala de grises
// 		double	t; //numero entre 0 y 1
// 		int		shade; //número entre  (negro) y 255 (blanco)
// 		int		color; //color RGB en formato 0xRRGGBB

// 		t = (double)i / fractal->max_iterations; //calculo proporciones
// 		// Prueba 1: escapadas rápidas claras, lentas oscuras:
// 		shade = (int)(255 * (1.0 - t)); // así el shade estara entre 0-255
// 		// Si quieres lo contrario, usa: shade = (int)(255 * t);
// 		//construyo el color
// 		color = (shade << 16) | (shade << 8) | shade;
		
// 		// // colores arcoiris suaves basados en la proporción de escape
// 		// double	t;
// 		// int		r;
// 		// int		g;
// 		// int		b;
// 		// int		color;

// 		// t = (double)i / fractal->max_iterations;

// 		// r = (int)(128 + 127 * sin(6.2831 * t + 0.0));
// 		// g = (int)(128 + 127 * sin(6.2831 * t + 2.094));   // 2π/3
// 		// b = (int)(128 + 127 * sin(6.2831 * t + 4.188));   // 4π/3

// 		// color = (r << 16) | (g << 8) | b;
// 		put_color_to_pixel(fractal, fractal->x, fractal->y, color);
// 	}
// }
