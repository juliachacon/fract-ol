/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 23:02:36 by julia             #+#    #+#             */
/*   Updated: 2025/05/15 22:10:42 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int main(void)
{
    char c;
    int fd;

    fd = 1;// salida estándar (pantalla)
    c = 'a';

    ft_putchar_fd(c, fd);
    ft_putchar_fd('\n', fd); //imprime salto de linea
    return(0);
}*/