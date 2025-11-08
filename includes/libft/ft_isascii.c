/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:04:30 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/14 19:07:25 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*int	main(void)
{
	char c;

	c = '0';
	if (isascii(c))
		printf("'%c' is ascii", c);
	else
		printf("'%c is not ascii", c);
	if (ft_isascii(c))
		printf("'%c' is ascii", c);
	else
		printf("'%c is not ascii", c);
	return (0);
}*/