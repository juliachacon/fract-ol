/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:56:24 by julia             #+#    #+#             */
/*   Updated: 2025/05/16 20:05:30 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	char			*copy;
	unsigned int	i;
	size_t			s1_len;

	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (start >= s1_len)
		return (ft_strdup(""));
	if (len > (s1_len - start))
		len = (s1_len - start);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s1[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/* 
int main(void)
{
	char const *s1 = "hola";
	unsigned int start = 1;
	size_t len = 10;
	char *copy;

	copy = ft_substr(s1, start, len);
	printf("copy %s\n", copy);
	printf("original %s\n", s1);
	free(copy);
	return(0);
} */