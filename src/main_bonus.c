/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:09:12 by jchacon-          #+#    #+#             */
/*   Updated: 2025/11/16 17:09:14 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*  Displays the correct program usage when invalid arguments are provided.
 *  It shows all valid fractal options and how to pass Julia parameters.
 */
static void	print_usage(void)
{
	ft_putendl_fd("Usage: ./fractol mandelbrot", 1);
	ft_putendl_fd("   or: ./fractol julia", 1);
	ft_putendl_fd("   or: ./fractol julia <cx> <cy>", 1);
	ft_putendl_fd("   e.g.: ./fractol julia 0.8 0.156", 1);
	ft_putendl_fd("   or: ./fractol bship", 1);
}

/*  Sets the Julia set parameter c = cx + cy*i.
 *  If the user provides two extra arguments, they are used to define c.
 *  If not, default values are applied to generate the standard Julia set
 *  Also resets zoom and offsets when no custom parameters are provided.
 */

void	julia_parameters(t_fractal *fractal, int argc, char **argv)
{
	if (argc == 4)
	{
		fractal->cx = ft_atof(argv[2]);
		fractal->cy = ft_atof(argv[3]);
	}
	else if (argc == 2)
	{
		fractal->cx = -0.8;
		fractal->cy = 0.156;
		fractal->zoom = 230;
		fractal->offset_x = 0.0;
		fractal->offset_y = 0.0;
	}
}
/*  Selects which fractal to render based on the name provided.
 *  - "mandelbrot": draws the Mandelbrot set
 *  - "julia":      draws the Julia set
 *  - "bship":      draws the Burning Ship fractal
 *  If an invalid name is passed, usage is printed and the function returns 1.
 *  After drawing,
	the image is pushed to the window. Choose a fractal by argv[1]
 */

int	draw_fractal(t_fractal *fractal, char *query)
{
	if (ft_strncmp(query, "mandelbrot", 10) == 0)
	{
		fractal->name = "mandelbrot";
		draw_mandelbrot(fractal);
	}
	else if (ft_strncmp(query, "julia", 5) == 0)
	{
		fractal->name = "julia";
		draw_julia(fractal);
	}
	else if (ft_strncmp(query, "bship", 5) == 0)
	{
		fractal->name = "bship";
		draw_burning_ship(fractal);
	}
	else
	{
		print_usage();
		return (1);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
	return (0);
}

/*
** Entry point of the program.
**
** - Checks that at least one argument is provided.
** - Initializes the fractal structure and MiniLibX.
** - Validates the fractal name passed by the user.
** - For Julia: allows 0 or 2 additional parameters (cx and cy).
** - Calls the drawing function and sets up all event hooks:
**      * key presses
**      * mouse scroll for zoom
**      * window close event
**
** The program then enters the MLX loop and waits for events.
*/
int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc < 2)
		return (print_usage(), 0);
	init_fractal(&fractal);
	init_mlx(&fractal);
	if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		if (argc != 2 && argc != 4)
			return (print_usage(), 0);
		fractal.name = "julia";
		julia_parameters(&fractal, argc, argv);
	}
	else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		fractal.name = "mandelbrot";
	else if (ft_strncmp(argv[1], "bship", 5) == 0)
		fractal.name = "bship";
	else
		return (print_usage(), 0);
	draw_fractal(&fractal, fractal.name);
	mlx_key_hook(fractal.window, key_hook, &fractal);
	mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
	mlx_hook(fractal.window, 17, 0L, exit_fractal, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_fractal	fractal;

// 	if (argc < 2)
// 	{
// 		print_usage();
// 		return (1);
// 	}
// 	init_fractal(&fractal);
// 	init_mlx(&fractal);
// 	if (draw_fractal(&fractal, argv[1], argc, argv) != 0)
// 		return (1);
// 	mlx_key_hook(fractal.window, key_hook, &fractal);
// 	mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
// 	mlx_hook(fractal.window, 17, 0L, exit_fractal, &fractal);
// 	mlx_loop(fractal.mlx);
// 	return (0);
// }
