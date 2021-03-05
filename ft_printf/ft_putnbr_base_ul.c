/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 07:42:34 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/04 21:25:05 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_number_with_base(unsigned long number,
									const size_t base_length,
									const char *base)
{
	if (number >= base_length)
		print_number_with_base(number / base_length, base_length, base);
	ft_putchar(base[number % base_length]);
}

void		ft_putnbr_base_ul(unsigned long number, const char *base)
{
	const size_t	base_length = ft_strlen(base);

	if (ft_is_valid_base(base, base_length) == false)
		return ;
	print_number_with_base(number, base_length, base);
}
