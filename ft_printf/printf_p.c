/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/18 00:28:46 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_precision(t_printf *print_control,
								t_handle_p *control,
								t_parse_flags *flag_control)
{
	int		precision;

	if (unless(flag_control->has_precision))
		return ;
	if (flag_control->precision < (int)control->digit_count)
		return ;
	precision = flag_control->precision - control->digit_count;
	if (precision < 0)
		precision = 0;
	(print_control->chars_printed) += precision;
	while (precision--)
		ft_putchar('0');
}

static void	handle_padding(t_printf *print_control,
							t_handle_p *control,
							t_parse_flags *flag_control)
{
	int	padding;

	if (flag_control->has_precision)
		if (flag_control->precision >= flag_control->minimum_width)
			return ;
	if (flag_control->has_precision &&
		(flag_control->precision > control->digit_count))
		padding = flag_control->minimum_width - flag_control->precision;
	else
		padding = flag_control->minimum_width - control->digit_count;
	if (padding <= 0)
		return ;
	(print_control->chars_printed) += padding;
	while (padding--)
		ft_putchar(flag_control->left_padder);
}

static void	handle_left(t_printf *print_control,
						t_handle_p *control,
						t_parse_flags *flag_control)
{
	if (flag_control->is_left_padded_with_zeros)
	{
		if (unless(flag_control->is_left_justified))
			handle_padding(print_control, control, flag_control);
		handle_precision(print_control, control, flag_control);
		return ;
	}
	if (unless(flag_control->is_left_justified))
		handle_padding(print_control, control, flag_control);
	handle_precision(print_control, control, flag_control);
}

void		printf_p(t_printf *print_control,
						t_handle_p *control,
						t_parse_flags *flag_control)
{
	handle_left(print_control, control, flag_control);
	if (control->is_null)
	{
		ft_putstr("(nil)");
		(print_control->chars_printed) += 5;
		if (flag_control->is_left_justified)
			handle_padding(print_control, control, flag_control);
		return ;
	}
	ft_putstr("0x");
	ft_putnbr_base_ul(control->print_me, DOWNCASE_HEX_BASE);
	(print_control->chars_printed) += ft_count_digits_hex_ul(control->print_me) + 2;
	if (flag_control->is_left_justified)
		handle_padding(print_control, control, flag_control);
}