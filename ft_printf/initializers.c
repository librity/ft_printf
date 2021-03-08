/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 21:49:36 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/08 00:53:35 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_print_control(t_printf *print_control, const char *format)
{
	print_control->format = format;
	print_control->chars_printed = 0;
	print_control->conversion_position = 0;
	print_control->conversion = '\0';
}

void	initialize_int_control(t_printf *print_control,
								t_handle_int *int_control)
{
	int_control->print_me = 0;
	int_control->flags = (char *)(print_control->format);
	int_control->char_count = 0;
	int_control->digit_count = 0;
	int_control->has_wildcards = false;
	int_control->has_minimum_width = false;
	int_control->print_as_padding = false;
	int_control->minimum_width = 0;
	int_control->has_precision = false;
	int_control->precision = 0;
	int_control->padding = ' ';
	int_control->has_right_padding = false;
	int_control->right_padding = 0;
}

void	initialize_wildcard_control(t_printf *print_control,
									t_handle_int *int_control,
									t_parse_wildcards *wildcard_control)
{
	wildcard_control->conversion_position = print_control->conversion_position;
	wildcard_control->found_wildcards = ft_strnchr(int_control->flags, '*',
										wildcard_control->conversion_position);
	wildcard_control->parser = 0;
	wildcard_control->wildcard = 0;
}