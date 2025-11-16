/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:25:25 by jchacon-          #+#    #+#             */
/*   Updated: 2025/11/16 17:25:32 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>

// --- Window ---
# define SIZE 700
// # define WIDTH 800
// # define HEIGHT 600

// --- Mouse ---
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// --- Zoom ---
# define ZOOM_IN 1
# define ZOOM_OUT -1
# define MIN_ZOOM 0.0000001
# define MAX_ZOOM 1000000000.0

# define ITER_STEP 10
# define ITER_MIN 30
# define ITER_MAX 1000

// --- Keyboard ---
// Linux: MLX usa X11 keycodes
// Mac: MLX usa keycodes de Apple

# ifdef __linux__
#  define ESC 65307
#  define LEFT 65361
#  define UP 65362
#  define RIGHT 65363
#  define DOWN 65364

// Letters (Linux)
#  define KEY_R 114
#  define KEY_C 99
#  define KEY_J 106
#  define KEY_M 109
#  define KEY_P 112

# else
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define DOWN 125
#  define UP 126
#  define R 15

// Letras (Mac)
#  define KEY_R 15
#  define KEY_C 8
#  define KEY_J 38
#  define KEY_M 46
#  define KEY_P 35
# endif

typedef struct s_fractal
{
	char	*name;
	// MiniLibX
	void	*mlx;
	void	*window;
	void	*image;

	// Pixels buffer
	char	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	// Plot variables
	int		x;
	int		y;
	int		color;
	// Complex plane variables
	double	zx;
	double	zy;
	double	cx;
	double	cy;

	// Fractal parameters
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	zoom_level;
	int		max_iterations;
}			t_fractal;

// main
int			draw_fractal(t_fractal *fractal, char *query);

// init.c
void		init_fractal(t_fractal *fractal);
void		init_mlx(t_fractal *fractal);

// mandelbrot.c
void		calculate_mandelbrot(t_fractal *fractal);
void		calculate_julia(t_fractal *fractal);
void		calculate_burning_ship(t_fractal *fractal);

void		draw_mandelbrot(t_fractal *fractal);
void		draw_julia(t_fractal *fractal);
void		draw_burning_ship(t_fractal *fractal);

// utils.c
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int colour);
int			exit_fractal(t_fractal *fractal);
void		change_iterations(t_fractal *fractal, int key_code);
double		generate_random_c(void);
int			get_color(t_fractal *fractal, int i);

// ft_atof.c
double		ft_atof(const char *str);

// mouse_keys.c
void		zoom(t_fractal *fractal, int x, int y, int zoom);
int			key_hook(int key_code, t_fractal *fractal);
void		set_random_julia(double *cx, double *cy);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);

#endif