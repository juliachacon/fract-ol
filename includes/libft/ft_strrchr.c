/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 22:27:20 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/16 22:57:22 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return ((char *)last);
}

/*int main(void)
{
	char    c;
	char    *s;

	c = 'u';
	s = "juliamundo";

	char *result = ft_strrchr(s, c);
	char *result2 = strrchr(s, c);
	printf("%s\n", result);
	printf("%s", result2);
	// printf("%p\n", s);
	// s = s + 1;
	// printf("%p", s);
	return(0);
}*/