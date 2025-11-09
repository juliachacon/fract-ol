/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:37:21 by julia             #+#    #+#             */
/*   Updated: 2025/11/09 23:38:24 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int colour)
{
	char	*dst;

	// 1. Comprobamos que el píxel está dentro de la ventana
	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
		return ;

	// 2. Calculamos la dirección de memoria del píxel (x, y)
	dst = fractal->pointer_to_image
		+ (y * fractal->size_line + x * (fractal->bits_per_pixel / 8));

	// 3. Escribimos el color en esa dirección
	*(unsigned int *)dst = colour;
}


int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}
