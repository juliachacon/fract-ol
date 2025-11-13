/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:13:03 by julia             #+#    #+#             */
/*   Updated: 2025/11/13 20:04:09 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	ft_putendl_fd("Usage: ./fractol mandelbrot", 1);
	ft_putendl_fd("   or: ./fractol julia", 1);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;
//control de argumentos de entrada
	if (argc != 2 
		|| (ft_strncmp(argv[1], "mandelbrot", 10) != 0 
		&& ft_strncmp(argv[1], "julia", 5) != 0))
	{
		print_usage();
		return (1);
	}
// Inicializar estructura fractal	
	init_fractal(&fractal);
	
// Inicializar MLX 
	init_mlx(&fractal);
// 4) Elegir fractal según argv[1]
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		// init_fractal ya está preparado para mandelbrot
		draw_mandelbrot(&fractal);
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		// Para Julia necesitamos fijar cx y cy (la "semilla")
		// Prueba esta combinación (clásica):
		fractal.cx = -0.8;
		fractal.cy = 0.156;
		// Opcional: puedes ajustar zoom/offset para julia si quieres otra vista
		// fractal.zoom = 250.0;
		// fractal.offset_x = 0.0;
		// fractal.offset_y = 0.0;
		draw_julia(&fractal);
	}	

// Mostrar la imagen en la ventana
mlx_put_image_to_window(fractal.mlx, fractal.window, 
	fractal.image, 0, 0);
	
// Hooks de teclado / ratón / cerrar ventana (opcional pero típico)
//	mlx_key_hook(fractal.window, key_hook, &fractal);
//	mlx_mouse_hook(fractal.window, mouse_hook, &fractal);
	mlx_hook(fractal.window, 17, 0L, exit_fractal, &fractal);
// Bucle de eventos	
	mlx_loop(fractal.mlx);
	return (0);
}
