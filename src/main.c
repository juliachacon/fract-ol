/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:13:03 by julia             #+#    #+#             */
/*   Updated: 2025/11/15 17:49:58 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	ft_putendl_fd("Usage: ./fractol mandelbrot", 1);
	ft_putendl_fd("   or: ./fractol julia", 1);
	ft_putendl_fd("   or: ./fractol bship", 1);
	// ft_putendl_fd("   or: ./fractol ship", 1);
}

// Elegir fractal según argv[1]
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
		if (fractal->cx == 0.00 && fractal->cy == 0.0)
		{// Para Julia necesitamos fijar cx y cy
		fractal->cx = -0.8;
		fractal->cy = 0.156;
		fractal->zoom = 230.0;
		fractal->offset_x = 0.0;
		fractal->offset_y = 0.0;
		}
		draw_julia(fractal);
	}
	else if (ft_strncmp(query, "bship", 5) == 0)
	{
		fractal->name = "bship";
		draw_burning_ship(fractal);
	}
	// else if (ft_strncmp(query, "ship", 5) == 0)
	// 	draw_burning_ship(fractal);
	else
	{
		print_usage();
		return (1);
	}
// Mostrar la imagen en la ventana
	mlx_put_image_to_window(fractal->mlx, fractal->window, 
		fractal->image, 0, 0);
	return(0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
//control de argumentos de entrada
	if (argc != 2)
	{
		print_usage();
		return (1);
	}
// Inicializar estructura fractal	
	init_fractal(&fractal);
// Inicializar MLX 
	init_mlx(&fractal);
	// if (ft_strncmp(argv[1], "julia", 5) == 0)
	// {
	// 	fractal.cx = -0.8;
	// 	fractal.cy = 0.156;
	// 	// fractal.offset_x = -1.5;   // prueba valores aquí
	// 	// fractal.offset_y = -1.5;
	// }
	if (draw_fractal(&fractal, argv[1]) != 0)
		return (1);
// Hooks de teclado / ratón / cerrar ventana 
	mlx_key_hook(fractal.window, key_hook, &fractal);
	mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
	mlx_hook(fractal.window, 17, 0L, exit_fractal, &fractal);
// Bucle de eventos	
	mlx_loop(fractal.mlx);
	return (0);
}


	