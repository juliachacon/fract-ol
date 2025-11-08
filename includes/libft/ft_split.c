/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:11:41 by julia             #+#    #+#             */
/*   Updated: 2025/05/16 20:07:40 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_iniciate_vars(size_t *i, size_t *j)
{
	*i = 0;
	*j = 0;
}

size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

void	*ft_free_lst(char **lst, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(lst[i]);
		i++;
	}
	free(lst);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	i;
	size_t	j;
	size_t	word_start;

	ft_iniciate_vars(&i, &j);
	if (s == NULL)
		return (NULL);
	lst = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (lst == NULL)
		return (NULL);
	while (s[i] && j < (ft_count_words(s, c)))
	{
		while (s[i] == c)
			i++;
		word_start = i;
		while (s[i] && s[i] != c)
			i++;
		lst[j] = ft_substr(s, word_start, i - word_start);
		if (lst[j] == NULL)
			return (ft_free_lst(lst, j));
		j++;
	}
	lst[j] = NULL;
	return (lst);
}

/*
int	main(void)
{
	char *s = "julia,mundo,hola";
	char **resultado;
	int i = 0;

	printf("Test 1:\n");
	resultado = ft_split(s, ',');
	if (!resultado)
		return (1); // control si ft_split falla
	while (resultado[i])
	{
		printf("Word%d: %s\n", i, resultado[i]);
		free(resultado[i]);
		i++;
	}
	free(resultado);
	return (0);
} */