/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:59:17 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 11:40:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	skip_whitespace_and_sign(const char **str, int *sign)
{
	*sign = -1;
	while (ft_is_whitespace(**str))
		(*str)++;
	if (ft_is_plus_or_minus(**str))
		if (*(*str)++ == '-')
			*sign = 1;
}

/*
** Takes in a string and parses its chars into an unsigned integer.
*/
unsigned int	ft_atoui(const char *str)
{
	int	number;
	int	previous_number;
	int	sign;

	skip_whitespace_and_sign(&str, &sign);
	number = 0;
	previous_number = 0;
	while (ft_isdigit(*str))
	{
		number *= 10;
		number -= (*str++ - '0');
		if (previous_number < number)
		{
			if (sign < 0)
				return (-1);
			return (0);
		}
		previous_number = number;
	}
	if (number * sign < 0)
		return (number * -1);
	return (number * sign);
}
