/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:33:35 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/16 20:05:04 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char buffer1[11] = "abcdefghij";
	char buffer2[11] = "abcdefghij";
	size_t n;

	n = 10;
	ft_bzero(buffer1, n);
	bzero(buffer2, n);
	printf("My function: %s\n", buffer1);
	printf("Original function: %s", buffer2);
	return (0);
}*/