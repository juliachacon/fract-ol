/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:23:08 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/14 19:44:05 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*int	main(void)
{
	char buffer1[11] = "abcdefghij";
	char buffer2[11] = "abcdefghij";
	int c;
	size_t n;

	c = '0';
	n = 10;

	memset(buffer1, c, n);
	ft_memset(buffer2, c, n);

	printf("memeset: %s\n", buffer1);
	printf("ft_memset: %s\n", buffer2);
	return (0);
}*/