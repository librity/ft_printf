/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_plus_or_minus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:47:06 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 11:40:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Advances a char pointer until it stops pointing at an ASCII '+' or '-'.
*/
char	*ft_skip_plus_or_minus(char *digits)
{
	while (ft_is_plus_or_minus(*digits))
		digits++;
	return (digits);
}
