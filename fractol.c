/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julia <julia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 01:58:52 by julia             #+#    #+#             */
/*   Updated: 2025/11/09 01:58:54 by julia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();                      // Inicializa MiniLibX
    win = mlx_new_window(mlx, 800, 600, "Fract-ol"); // Crea una ventana 800x600
    mlx_loop(mlx);                         // Espera eventos (mantiene la ventana abierta)
}
