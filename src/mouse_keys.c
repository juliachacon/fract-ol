/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:06:03 by julia             #+#    #+#             */
/*   Updated: 2025/11/16 15:35:30 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * zoom:
 * Updates the zoom factor and complex plane offsets so that zooming
 * is centered around the mouse position (x, y). It prevents zooming
 * beyond MIN_ZOOM and MAX_ZOOM limits and keeps the selected point
 * under the cursor while zooming in or out.
 */
void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	zoom_level = fractal->zoom_level;
	if (zoom == ZOOM_IN)
	{
		if (fractal->zoom * zoom_level > MAX_ZOOM)
			return ;
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom * zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom * zoom_level));
		fractal->zoom *= zoom_level;
	}
	else if (zoom == ZOOM_OUT)
	{
		if (fractal->zoom / zoom_level < MIN_ZOOM)
			return ;
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x
				/ (fractal->zoom / zoom_level));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y
				/ (fractal->zoom / zoom_level));
		fractal->zoom /= zoom_level;
	}
	else
		return ;
}

/*
 * set_random_julia:
 * Assigns random values to the real (cx) and imaginary (cy) parts of
 * the Julia parameter c by calling generate_random_c(). This allows
 * generating a new random Julia set configuration.
 */
void	set_random_julia(double *cx, double *cy)
{
	*cx = generate_random_c();
	*cy = generate_random_c();
}

/*
 * key_hook:
 * Handles keyboard input to control the fractal:
 * - ESC closes the program.
 * - Arrow keys translate the view by updating offsets.
 * - 'R' resets the fractal parameters.
 * - 'C' changes the color palette.
 * - 'J' sets a random Julia parameter.
 * - 'M' and 'P' decrease or increase the max iteration count.
 * After processing the key, the fractal is redrawn.
 */
int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit_fractal(fractal);
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (key_code == KEY_R)
		init_fractal(fractal);
	else if (key_code == KEY_C)
		fractal->color += (255 * 255 * 255) / 100;
	else if (key_code == KEY_J)
		set_random_julia(&fractal->cx, &fractal->cy);
	else if (key_code == KEY_M || key_code == KEY_P)
		change_iterations(fractal, key_code);
	draw_fractal(fractal, fractal->name);
	return (0);
}

/*
 * mouse_hook:
 * Handles mouse events related to zoom:
 * - Scroll up zooms in around the mouse position.
 * - Scroll down zooms out around the mouse position.
 * After updating the zoom, the fractal is redrawn.
 */
int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, ZOOM_IN);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, ZOOM_OUT);
	draw_fractal(fractal, fractal->name);
	return (0);
}
