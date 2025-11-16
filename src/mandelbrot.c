/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:24:39 by julia             #+#    #+#             */
/*   Updated: 2025/11/16 15:12:18 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Computes the color of a single pixel for the Mandelbrot set.
**
** The Mandelbrot set is defined by iterating the complex function:
**        Z(n+1) = Z(n)^2 + C
** starting at Z(0) = 0.
** Zx = real part of Z, starts at 0
** Zy = imaginary part of Z, starts at 0
** Each pixel corresponds to a complex value C.
** We iterate Z until it "escapes" (its magnitude >= 2) or reaches the
** maximum number of iterations. The number of iterations determines its color.
*/

/*
** Convert pixel coordinates (x, y) into the complex plane.
**
** (x - SIZE/2) centers the image.
** Dividing by zoom scales the coordinates.
** Adding offset_x/y allows the user to pan around the plane.
**
** cx and cy form the complex number C = (cx + i*cy).
*/

/*
** Main Mandelbrot iteration loop.
** We repeatedly apply the function Z = Z^2 + C.
** Compute the new real part:
**   Zx_new = Zx^2 - Zy^2 + Cx
**
** (Zx^2 - Zy^2) is the real part of Z^2 in complex arithmetic.
** We store it in a temporary variable because Zx is used again
** when computing Zy.
** Compute the new imaginary part:
**   Zy_new = 2 * Zx * Zy + Cy
**
** This is the imaginary part of Z^2 plus the imaginary part of C.
*/

/*
** Escape condition:
** If |Z|^2 = Zx^2 + Zy^2 >= 4, the point escapes to infinity.
**
** (We compare to 4 instead of 2 because it's faster than sqrt).
*/

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	fractal->name = "mandelbrot";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = ((fractal->x - SIZE / 2.0) / fractal->zoom)
		+ fractal->offset_x;
	fractal->cy = ((fractal->y - SIZE / 2.0) / fractal->zoom)
		+ fractal->offset_y;
	while (i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy >= 4)
			break ;
		i++;
	}
	put_color_to_pixel(fractal, fractal->x, fractal->y, get_color(fractal, i));
}

	/*
	** After the loop, color the pixel:
	** - If i == max_iterations → point is inside (paint black).
	** - Otherwise → use i to compute a smooth gradient.
	*/

/*if (i == fractal->max_iterations)
	put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
else
	put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color
* i));
*/