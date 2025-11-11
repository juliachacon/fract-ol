/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:37:21 by julia             #+#    #+#             */
/*   Updated: 2025/11/11 12:53:52 by julia            ###   ########.fr       */
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
	// Solo liberar si realmente se usó malloc
	if (fractal->mlx)
		free(fractal->mlx);
	if (fractal)
		free(fractal);
	exit(0); // salida normal
}

// int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
// {
// 	if (mouse_code == SCROLL_UP)
// 		zoom(fractal, x, y, 1);
// 	else if (mouse_code == SCROLL_DOWN)
// 		zoom(fractal, x, y, -1);
// 	draw_fractal(fractal, fractal->name);
// 	return (0);
// }

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == 65307)
		exit_fractal(fractal);
	else if (key_code == 65361)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == 65363)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == 65362)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == 65364)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == 114)
		init_fractal(fractal);
	// else if (key_code == C)
	// 	fractal->color += (255 * 255 * 255) / 100;
	// else if (key_code == J)
	// 	set_random_julia(&fractal->cx, &fractal->cx);
	// else if (key_code == M || key_code == P)
	// 	change_iterations(fractal, key_code);
	// draw_fractal(fractal, fractal->name);
	return (0);
}
