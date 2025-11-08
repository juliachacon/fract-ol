/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:20:30 by julia             #+#    #+#             */
/*   Updated: 2025/05/15 22:07:42 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* void	ft_flip_case(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

void	ft_even_uppercase(unsigned int i, char *c)
{
	if (i % 2 == 0 && (*c >= 'a' && *c <= 'z'))
	{
		*c = *c - 32;
	}
}

int	main(void)
{
	char	s[] = "juliamundo";
	char	str[] = "julia42";

	ft_striteri(s, ft_even_uppercase);
	ft_striteri(str, ft_flip_case);
	printf("string transformada ft_even: %s\n", s);
	printf("string transformada ft_flip: %s\n", str);
	return (0);
} */