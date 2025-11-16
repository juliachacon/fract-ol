/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:37:21 by julia             #+#    #+#             */
/*   Updated: 2025/11/16 15:04:51 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Writes a color value into a specific pixel of the image buffer.
** - First checks if (x, y) is inside the window boundaries.
** - Computes the memory address of the pixel inside the MLX image buffer.
** - Stores the color value at that address.
*/
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int colour)
{
	char	*dst;

	if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
		return ;
	dst = fractal->pointer_to_image + (y * fractal->size_line + x
			* (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

/*
** Safely closes the fractal program:
** - Destroys the MLX image (if it exists)
** - Destroys the MLX window (if it exists)
** - Frees the MLX display and the MLX pointer (Linux requirement)
** - Exits the program
*/
int	exit_fractal(t_fractal *fractal)
{
	if (fractal->image)
		mlx_destroy_image(fractal->mlx, fractal->image);
	if (fractal->window)
		mlx_destroy_window(fractal->mlx, fractal->window);
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit(0);
	return (0);
}

/*
** Generates a random double between -1.5 and 1.5.
** Used to slightly change the Julia constant C when requested.
*/
double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}
/*
** Increases or decreases the maximum number of iterations.
** KEY_M → decrease iterations (faster render, less detail)
** KEY_P → increase iterations (slower render, more detail)
*/

void	change_iterations(t_fractal *fractal, int key_code)
{
	if (key_code == KEY_M)
	{
		if (fractal->max_iterations > ITER_MIN)
			fractal->max_iterations -= ITER_STEP;
	}
	else if (key_code == KEY_P)
	{
		if (fractal->max_iterations < ITER_MAX)
			fractal->max_iterations += ITER_STEP;
	}
}
/*
** Computes the color of a pixel based on:
** - The number of iterations (i)
** - The maximum number of iterations
** - The base color chosen for the fractal
**
** If the point did not escape (i == max_iterations),
** we return pure black (inside the fractal).
**
** Otherwise:
** We compute a shading factor (shade), based on how quickly it escaped.
** Then each RGB component of the base color is scaled by this shade.
*/

int	get_color(t_fractal *fractal, int i)
{
	double	t;
	int		shade;
	int		color;

	if (i == fractal->max_iterations)
		return (0x000000);
	t = (double)i / fractal->max_iterations;
	shade = (int)(255 * (1.0 - t));
	color = fractal->color;
	return (((((color >> 16) & 0xFF) * shade)
			/ 255) << 16 | ((((color >> 8) & 0xFF) * shade)
			/ 255) << 8 | (((color & 0xFF) * shade) / 255));
}

// int	get_color(t_fractal *fractal, int i)
// {
// 	double	t;
// 	int		shade;
// 	int		base;
// 	int		br;
// 	int		bg;
// 	int		bb;
// 	int		r;
// 	int		g;
// 	int		b;

// 	if (i == fractal->max_iterations)
// 		return (0x000000);

// 	t = (double)i / fractal->max_iterations; //shade según iteraciones
// 	shade = (int)(255 * (1.0 - t)); // 255 cerca del borde, 0 lejos

// 	base = fractal->color; //color base cambia con C
// 	br = (base >> 16) & 0xFF;
// 	bg = (base >> 8) & 0xFF;
// 	bb = base & 0xFF;

// 	r = (br * shade) / 255;//escalar por el shade
// 	g = (bg * shade) / 255;
// 	b = (bb * shade) / 255;

// 	return ((r << 16) | (g << 8) | b);
// }
