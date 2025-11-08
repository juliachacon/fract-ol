/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:34:51 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/14 19:06:48 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*int	main(void)
{
	int	c;

	c = 1;
	if (isalnum(c))
	{
		printf("'%d' is a num", c);
	}
	else
	{
		printf("'%d' is not a num", c);
	}
	if (ft_isalnum(c))
	{
		printf("'%d' is a num", c);
	}
	else
	{
		printf("'%d' is not a num", c);
	}
 return(0);
} */