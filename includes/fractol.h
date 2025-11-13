/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:49:43 by julia             #+#    #+#             */
/*   Updated: 2025/11/13 18:32:45 by julia            ###   ########.fr       */
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
	char *name;
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
	// Variables del plano complejo
	double	zx;                 // parte real de z
	double	zy;                 // parte imaginaria de z
	double	cx;                 // parte real de c (mapeada desde x)
	double	cy;                 // parte imaginaria de c (mapeada desde y)
	
	// Parámetros del fractal
	double	offset_x;           // desplazamiento en el eje X
	double	offset_y;           // desplazamiento en el eje Y
	double	zoom;               // zoom inicial
	int		max_iterations;     // nº máximo de iteraciones
}	t_fractal;

// init.c
void	init_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);

//mandelbrot.c
void	calculate_mandelbrot(t_fractal *fractal);


// draw.c
void	draw_mandelbrot(t_fractal *fractal);

// utils.c
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
int	exit_fractal(t_fractal *fractal);
// int			key_hook(int key_code, t_fractal *fractal);
// int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

# ifdef __linux__
#  define ESC		65307
#  define LEFT		65361
#  define UP		65362
#  define RIGHT	65363
#  define DOWN		65364
#  define R		114
# else
#  define ESC		53
#  define LEFT		123
#  define RIGHT	124
#  define DOWN		125
#  define UP		126
#  define R		15
#endif

#endif