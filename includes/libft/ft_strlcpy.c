/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:40:52 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/16 22:40:19 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*#include <bsd/string.h>

int	main(void)
{
	char dst[20]; // buffer de 10 caracteres
	const char src[] = "ffff";
	size_t size;
	size_t res;
	size_t res2;

	size = 0;

	res = strlcpy(dst, src, size);
	printf("%zu :resultado es tamaño de src\n", res);
	printf("%s :destino\n", dst);
	res2 = ft_strlcpy(dst, src, size);
	printf("%zu :mi resultado es tamaño de src\n", res2);
	printf("%s :mi destino\n", dst);
}*/