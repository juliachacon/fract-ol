/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:04:38 by julia             #+#    #+#             */
/*   Updated: 2025/05/15 22:18:28 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (s == NULL || f == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*char	ft_even_uppercase(unsigned int i, char c)
{
	if (i % 2 == 0 && (c >= 'a' && c <= 'z'))
	{
		c = c - 32;
	}
	return (c);
}
//c es un char que es un valor en s

int	main(void)
{
	char s[] = "juliamundo";
	char *result;
	result = ft_strmapi(s, ft_even_uppercase);
	printf("resultado: %s\n", result);
	return (0);
}*/