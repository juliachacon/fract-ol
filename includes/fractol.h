/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:49:43 by julia             #+#    #+#             */
/*   Updated: 2025/11/15 17:52:50 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h> // AQUI está rand() y RAND_MAX

// --- Window ---
# define SIZE 700
// # define WIDTH 800
// # define HEIGHT 600

// --- Mouse ---
# define SCROLL_UP   4
# define SCROLL_DOWN 5

// --- Zoom ---
# define ZOOM_IN 1
# define ZOOM_OUT -1
# define MIN_ZOOM 0.0000001
# define MAX_ZOOM 1000000000.0

# define ITER_STEP 50
# define ITER_MIN 50
# define ITER_MAX 5000

// --- Keyboard ---
// Linux: MLX usa X11 keycodes
// Mac: MLX usa keycodes de Apple

# ifdef __linux__
#  define ESC		65307
#  define LEFT		65361
#  define UP		65362
#  define RIGHT	65363
#  define DOWN		65364

// Letras (Linux)
#  define KEY_R      114
#  define KEY_C      99
#  define KEY_J      106
#  define KEY_M      109
#  define KEY_P      112

# else
#  define ESC		53
#  define LEFT		123
#  define RIGHT	124
#  define DOWN		125
#  define UP		126
#  define R		15

// Letras (Mac)
#  define KEY_R      15
#  define KEY_C      8
#  define KEY_J      38
#  define KEY_M      46
#  define KEY_P      35
#endif

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
	double zoom_level;			// zoom sensibility
	int		max_iterations;     // nº máximo de iteraciones
}	t_fractal;

// main
int		draw_fractal(t_fractal *fractal, char *query);

// init.c
void	init_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);

//mandelbrot.c
void	calculate_mandelbrot(t_fractal *fractal);
void    calculate_julia(t_fractal *fractal);
void	calculate_burning_ship(t_fractal *fractal);

// draw.c
void	draw_mandelbrot(t_fractal *fractal);
void    draw_julia(t_fractal *fractal);
void	draw_burning_ship(t_fractal *fractal);

// utils.c
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
int	exit_fractal(t_fractal *fractal);
void	change_iterations(t_fractal *fractal, int key_code);
double  generate_random_c(void);
int	get_color(t_fractal *fractal, int i);

//mouse_keys.c
void	zoom(t_fractal *fractal, int x, int y, int zoom);
int		key_hook(int key_code, t_fractal *fractal);
void	set_random_julia(double *cx, double *cy);
int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

#endif