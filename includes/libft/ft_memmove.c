/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:08:34 by julia             #+#    #+#             */
/*   Updated: 2025/05/15 22:31:23 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	s = src;
	d = dest;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}

/*int	main(void)
{
	char	str[20] = "juliamundo";
	char	strr[20] = "juliamundo";

	printf("Antes de ft_memmove: %s\n", str);
	printf("Antes de memmove: %s\n", strr);
	// Copiar los primeros 5 caracteres "julia" a partir de str[5]
	ft_memmove(str + 5, str, 5);
	memmove(strr + 5, strr, 5);
	printf("Despues de ft_memmove: %s\n", str);
	printf("Despues de memmove: %s\n", strr);
	return (0);
}*/
