/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:23:33 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/14 21:49:32 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	else
	{
		while (src[i] != '\0' && size > (dst_len + i + 1))
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}

/*#include <bsd/string.h>

int	main(void)
{
	char	a1[] = "hola  ";
	char	a2[] = "hola  ";
	char	b[] = "mundo";

	printf("Mi función: %zu, %s\n", ft_strlcat(a1, b, 2), a1);
	printf("  Original: %zu, %s\n", strlcat(a2, b, 2), a2);
	return (0);
}*/