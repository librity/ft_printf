/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handled_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/14 12:32:50 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_print_me(t_printf *print_control, t_handle_int *control)
{
	control->print_me = va_arg(print_control->elements, int);
	control->char_count = ft_count_chars_i(control->print_me);
	control->digit_count = ft_count_digits_i(control->print_me);
	if (control->print_me < 0)
		control->is_negative = true;
}

static void	initialize_int_control(t_printf *print_control,
								t_handle_int *int_control)
{
	int_control->print_me = 0;
	int_control->digit_count = 0;
	int_control->char_count = 0;
	int_control->is_negative = false;
	int_control->is_zero_with_zero_precision = false;
	initialize_flag_control(print_control, &(int_control->flag_control));
}

bool		handled_int(t_printf *print_control)
{
	t_handle_int	control;
	t_parse_flags	*flag_control;

	if (print_control->conversion != 'd' && print_control->conversion != 'i')
		return (false);
	initialize_int_control(print_control, &control);
	flag_control = &(control.flag_control);
	parse_flags(print_control, flag_control);
	set_print_me(print_control, &control);
	if (flag_control->has_precision)
		if (flag_control->precision == 0 && control.print_me == 0)
			control.is_zero_with_zero_precision = true;
	printf_int(print_control, &control, flag_control);
	return (true);
}
