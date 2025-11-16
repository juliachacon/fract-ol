/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 20:35:04 by julia             #+#    #+#             */
/*   Updated: 2025/11/16 15:05:29 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initializes all fields of the fractal structure with default values.
** These values define:
** - Starting position
** - Default color
** - Initial zoom settings
** - Offsets to center the fractal
** - Initial iteration limit
** - Parameters cx and cy (used for Julia sets)
*/

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 233.33;
	fractal->zoom_level = 1.42;
	fractal->offset_x = -0.5;
	fractal->offset_y = 0.0;
	fractal->max_iterations = 120;
	fractal->cx = 0.0;
	fractal->cy = 0.0;
}
/*
** Initializes all MLX-related components:
** - Creates the MLX connection
** - Creates the program window
** - Creates an image inside the window
** - Gets a pointer to the image buffer for pixel manipulation
**
** mlx_get_data_addr also fills:
** - bits_per_pixel: number of bits used for each pixel
** - size_line: number of bytes per image row
** - endian: endianness of the pixel format
*/

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
}
