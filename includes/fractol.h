/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:49:43 by julia             #+#    #+#             */
/*   Updated: 2025/11/09 20:42:02 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "mlx.h"
# include <math.h>
// # include <pthread.h>

# define SIZE 700
// # define WIDTH 800
// # define HEIGHT 600
// # define THREAD_WIDTH 7
// # define THREAD_NUMBER 100

// # define SCROLL_UP 4
// # define SCROLL_DOWN 5

typedef struct s_fractal
{
	// MiniLibX
	void	*mlx;               // conexión con mlx
	void	*window;            // puntero a la ventana
	void	*image;             // puntero a la imagen (lienzo)

	// Buffer de píxeles
	char	*pointer_to_image;  // dirección del array de píxeles
	int		bits_per_pixel;     // bits por píxel
	int		size_line;          // bytes por línea
	int		endian;             // endianness (no te preocupes mucho)

	// Variables de dibujo
	int		x;                  // coordenada x actual (píxel)
	int		y;                  // coordenada y actual (píxel)
	int		color;              // color actual

	// Parámetros del fractal
	double	offset_x;           // desplazamiento en el eje X
	double	offset_y;           // desplazamiento en el eje Y
	double	zoom;               // zoom inicial
	int		max_iterations;     // nº máximo de iteraciones
}	t_fractal;

// init.c
void	init_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);

// draw / utils (lo crearás luego)
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);

#endif