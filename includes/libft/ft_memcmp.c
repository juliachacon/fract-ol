/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:25:43 by julia             #+#    #+#             */
/*   Updated: 2025/05/16 22:38:14 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			return (p1[i] - p2[i]);
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char	a[] = "judia";
	char	b[] = "julia";
	int		result;
	int		result2;

	result = ft_memcmp(a, b, 5);
	result2 = memcmp(a, b, 5);
	printf("result ft_memcmp: %d\n", result);
	printf("result memcmp: %d\n", result2);
	return (0);
} */
