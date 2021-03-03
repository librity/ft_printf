/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 03:18:33 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/03 03:18:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_int(int *chars_printed, int print_me)
{
	ft_putnbr(print_me);
	if (print_me < 0)
		(*chars_printed)++;
	*chars_printed += ft_count_digits(print_me);
}
