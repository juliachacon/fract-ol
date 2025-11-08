/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:00:18 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/14 19:07:53 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int	main(void)
{
	char c;

	c = 'A';
	if (isprint(c))
		printf("'%c' is print", c);
	else
		printf("'%c is not print", c);
	if (ft_isprint(c))
		printf("'%c' is print", c);
	else
		printf("'%c is not print", c);
	return (0);
}*/