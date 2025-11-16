/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchacon- <jchacon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:48:07 by jchacon-          #+#    #+#             */
/*   Updated: 2025/11/16 16:08:36 by jchacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Simple implementation of a string-to-double conversion function.
**
** This function parses a numeric string and converts it into a double
** value, supporting:
**  - leading whitespace,
**  - optional '+' or '-' sign,
**  - integer part,
**  - optional decimal part after a dot '.'.
**
** The fractional part is handled by a helper function (parse_decimal), which
** processes each digit after the decimal point by multiplying it by a
** decreasing decimal factor (0.1, 0.01, 0.001, ...).
**
** The goal of this implementation is to provide a lightweight alternative
** to the standard atof/strtod functions, which are not allowed in 42
** projects. It is specifically designed for handling floating-point
** parameters passed to the Julia fractal.
*/

static void	parse_dec(const char *str, int *i, double *result)
{
	double	decimal;

	decimal = 0.1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			*result += (str[*i] - '0') * decimal;
			decimal *= 0.1;
			(*i)++;
		}
	}
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	int		i;

	result = 0.0;
	sign = 1.0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	parse_dec(str, &i, &result);
	return (result * sign);
}
