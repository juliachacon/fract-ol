/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:34:30 by julia             #+#    #+#             */
/*   Updated: 2025/05/14 21:13:57 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	s = src;
	d = dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	src[] = "juliamundo";
	char	dest1[20];
	char	dest2[20];

	ft_memcpy(dest1, src, 5);
	memcpy(dest2, src, 5);
	dest1[5] = '\0';
	dest2[5] = '\0';
	printf("destino 1: %s\n", dest1);
	printf("destino 2: %s\n", dest2);
	return (0);
}*/
