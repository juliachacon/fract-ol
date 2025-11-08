/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 21:08:14 by jchacon-          #+#    #+#             */
/*   Updated: 2025/05/16 19:59:05 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*int main(void)
{
    char c;
    c = '0';
    if(isdigit(c))
    {
        printf("%d is digit", c);
    }
    else
    {
        printf("%d is not digit", c);
    }
    if(ft_isdigit(c))
    {
        printf("%d is digit", c);
    }
    else
    {
        printf("%d is not digit", c);
    }
    printf("%d", c);
    return(0);
}*/
