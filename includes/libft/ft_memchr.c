/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:34:32 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/16 19:58:02 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
		{
			return ((void *)ptr);
		}
		i++;
		ptr++;
	}
	return (NULL);
}

/* int	main(void)
{
	char s[11] = "juliamundo";
	char c = 'a';
	size_t n = 4;
	char *result = ft_memchr(s, c, n);
	char *result2 = memchr(s, c, n);
	printf("My result: %s\n", result);
	printf("Original: %s\n", result2);
	return (0);
} */