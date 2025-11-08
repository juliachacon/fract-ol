/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:29:31 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/16 20:00:52 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*int main(void)
{
    int c;
    c = 'A';
    if (isalpha(c))
    {
        printf("'%c' is alphabetic.\n", c);
    }
    else {
        printf("'%c' is not alphabetic.\n", c);
    }
    if (ft_isalpha(c))
    {
        printf("'%c' is alphabetic.\n", c);
    }
    else {
        printf("'%c' is not alphabetic.\n", c);
    }
    return(0);
}*/