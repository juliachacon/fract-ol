/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 20:16:39 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/14 21:58:48 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/*#include <stdio.h>
int main(void)
{
    char    c;
    char    *s;

    c = 'l';
    s = "hola";

    char *result = ft_strchr(s, c);
    char *result2 = strchr(s, c);
    printf("%s\n", result);
    printf("%s", result2);
    // printf("%p\n", s);
    // s = s + 1;
    // printf("%p", s);
    return(0);
}*/