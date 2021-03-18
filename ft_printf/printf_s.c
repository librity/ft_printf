/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/17 23:58:20 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void handle_padding(t_printf *print_control,
						   t_handle_s *control,
						   t_parse_flags *flag_control)
{
	int padding;

	if (flag_control->has_precision)
		if (control->precision_length > (size_t)flag_control->minimum_width)
			return;
	if (flag_control->has_precision)
		padding = flag_control->minimum_width - control->precision_length;
	else
		padding = flag_control->minimum_width - control->length;
	if (padding <= 0)
		return;
	(print_control->chars_printed) += padding;
	while (padding--)
		ft_putchar(flag_control->left_padder);
}

static void	handle_printing(t_printf *print_control,
							t_handle_s *control,
							t_parse_flags *flag_control)
{
	if (control->is_null)
	{
		ft_putstr("(null)");
		(print_control->chars_printed) += 6;
		return;
	}
	if (flag_control->has_precision)
	{
		ft_putstr_up_to(control->print_me, control->precision_length);
		(print_control->chars_printed) += control->precision_length;
		return;
	}
	ft_putstr(control->print_me);
	(print_control->chars_printed) += control->length;
}

void		printf_s(t_printf *print_control,
						t_handle_s *control,
						t_parse_flags *flag_control)
{
	if (unless(flag_control->is_left_justified))
		handle_padding(print_control, control, flag_control);
	handle_printing(print_control, control, flag_control);
	if (flag_control->is_left_justified)
		handle_padding(print_control, control, flag_control);
}
