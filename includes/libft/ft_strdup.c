/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:15:11 by julia             #+#    #+#             */
/*   Updated: 2025/05/16 20:06:56 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	copy = malloc(sizeof(char) * i + 1);
	if (!copy)
		return (NULL);
	while (j <= i)
	{
		copy[j] = s[j];
		j++;
	}
	return (copy);
}

/* int	main(void)
{
	const char s[] = "hola";
	char *copia;
	copia = ft_strdup(s);
	printf("original: %s\n", s);
	printf("copia: %s\n", copia);
	free(copia);
	return (0);
} */