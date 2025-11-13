/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 22:13:03 by julia             #+#    #+#             */
/*   Updated: 2025/11/13 18:03:56 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
//control de argumentos de entrada
	if (argc != 2 || ft_strncmp(argv[1], "mandelbrot", 10) != 0)
	{
		ft_putendl_fd("Usage: ./fractol mandelbrot", 1);
		return (1);
	}
// Inicializar estructura fractal	
	init_fractal(&fractal);
	
// Inicializar MLX 
	init_mlx(&fractal);
	
// Dibujar Mandelbrot en la imagen
	draw_mandelbrot(&fractal);
	
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
