/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:47:58 by julia             #+#    #+#             */
/*   Updated: 2025/05/16 20:05:53 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
			{
				return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
const char	*haystack = "holamundo";
const char	*needle = "mun";
char		*j;
size_t		len;

len = 8;
j = ft_strnstr(haystack, needle, len);
if (j)
printf("Found %s\n", j);
else
printf("Not found\n");
return (0);
}*/
