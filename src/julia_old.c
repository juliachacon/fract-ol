/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 19:42:26 by julia             #+#    #+#             */
/*   Updated: 2025/11/15 16:08:03 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(t_fractal *fractal)
{
	int		i;
	double	tmp;

	fractal->name = "julia";
	fractal->cx = ((fractal->x - SIZE / 2.0) / fractal->zoom) + fractal->offset_x;
	fractal->cy = ((fractal->y - SIZE / 2.0) / fractal->zoom) + fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= 4)
			break ;
	}
    if (i == fractal->max_iterations)
        put_color_to_pixel(fractal, fractal->x, fractal->y, 0xFFFFFF);
    else
    {
        // Puntos que escapan -> escala de grises
        double	t; //numero entre 0 y 1
        int		shade; //número entre  (negro) y 255 (blanco)
        int		color; //color RGB en formato 0xRRGGBB

        t = (double)i / fractal->max_iterations; //calculo proporciones
        // Prueba 1: escapadas rápidas claras, lentas oscuras:
        shade = (int)(255 * (1.0 - t)); // así el shade estara entre 0-255
        // Si quieres lo contrario, usa: shade = (int)(255 * t);
        //construyo el color
        color = (shade << 16) | (shade << 8) | shade;
		put_color_to_pixel(fractal, fractal->x, fractal->y, color);
	}
}