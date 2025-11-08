/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:53:38 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/16 19:58:21 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		len++;
	}
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

void	ft_fill_str(long nb, char *str, int *i)
{
	if (nb >= 10)
	{
		ft_fill_str(nb / 10, str, i);
	}
	str[*i] = (nb % 10) + '0';
	(*i)++;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;
	long	nb;

	nb = n;
	i = 0;
	len = ft_intlen(nb);
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		i++;
	}
	ft_fill_str(nb, str, &i);
	return (str);
}

/* int	main(void)
{
	int		n;
	char	*str;

	n = -2147483648;
	str = ft_itoa(n);
	printf("number: %s\n", str);
	free(str);
	return (0);
} */
