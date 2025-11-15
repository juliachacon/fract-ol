/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:37:21 by julia             #+#    #+#             */
/*   Updated: 2025/11/15 17:38:12 by julia            ###   ########.fr       */
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
	if (fractal->image)
	mlx_destroy_image(fractal->mlx, fractal->image);
	if (fractal->window)
	mlx_destroy_window(fractal->mlx, fractal->window);
	#ifdef __linux__
	if (fractal->mlx)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);   // el puntero de MLX, suele venir de malloc
	}
	#endif
	exit(0);
	return (0);
}

double	generate_random_c(void)
{
	return (((double)rand() / RAND_MAX) * 3.0 - 1.5);
}

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
	return (((((color >> 16) & 0xFF) * shade) / 255) << 16
		| ((((color >> 8) & 0xFF) * shade) / 255) << 8
		| (((color & 0xFF) * shade) / 255));
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
