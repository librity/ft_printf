/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handled_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 04:05:50 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/19 04:11:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	set_print_me(t_printf *print_control, t_handle_p *control)
{
	control->print_me = va_arg(print_control->elements, unsigned long);
	control->digit_count = ft_count_digits_hex_ul(control->print_me) + 2;
}

static void	initialize_control(t_printf *print_control,
									t_handle_p *control)
{
	control->print_me = 0;
	control->digit_count = 0;
	control->is_zero_with_zero_precision = false;
	initialize_flag_control(print_control, &(control->flag_control));
}

static void	interpret_flags(t_parse_flags *flag_control, t_handle_p *control)
{
	if (flag_control->has_precision)
		if (flag_control->precision == 0 && control->print_me == 0)
			control->is_zero_with_zero_precision = true;
}

bool		handled_p(t_printf *print_control)
{
	t_handle_p		control;
	t_parse_flags	*flag_control;

	if (print_control->conversion != 'p')
		return (false);
	initialize_control(print_control, &control);
	flag_control = &(control.flag_control);
	parse_flags(print_control, flag_control);
	set_print_me(print_control, &control);
	interpret_flags(flag_control, &control);
	printf_p(print_control, &control, flag_control);
	return (true);
}
