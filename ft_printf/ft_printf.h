/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 03:17:10 by lpaulo-m          #+#    #+#             */
/*   Updated: 2021/03/04 23:47:45 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

# define DECIMAL_BASE "0123456789"
# define DOWNCASE_HEX_BASE "0123456789abcdef"
# define UPPERCASE_HEX_BASE "0123456789ABCDEF"

int	ft_isdigit(int c);

size_t	ft_strlen(const char *s);
void	ft_strdel(char **delete_me);

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putendl(char *s);

bool	ft_is_valid_base(const char *base, const size_t base_length);
void	ft_putnbr_base(int number, char *base);
void	ft_putnbr_base_i(int number, char *base);
void	ft_putnbr_base_ui(unsigned int number, const char *base);
void	ft_putnbr_base_ul(unsigned long number, const char *base);

void	ft_putnbr(int n);
void	ft_putnbr_i(int number);
void	ft_putnbr_ui(int number);
void	ft_putnbr_ul(int number);

void	ft_puthex_uppercase(unsigned int number);
void	ft_puthex_downcase(unsigned int number);

int		ft_count_digits(int number);
int		ft_count_digits_i(int number);
int		ft_count_digits_i(int number);
int		ft_count_digits_ui(unsigned int number);
int		ft_count_digits_ul(unsigned long number);
int		ft_count_digits_hex_ul(unsigned long number);

bool	handled_no_conversion(const char **format, int *chars_printed);
bool	handled_double_percentage(const char **format, int *chars_printed);

bool	handled_s(const char **format,
					int *chars_printed,
					int conversion_posistion,
					va_list elements);
bool	handled_c(const char **format,
					int *chars_printed,
					int conversion_posistion,
					va_list elements);
bool	handled_int(const char **format,
					int *chars_printed,
					int conversion_posistion,
					va_list elements);
bool	handled_u(const char **format,
					int *chars_printed,
					int conversion_posistion,
					va_list elements);
bool	handled_p(const char **format,
						int *chars_printed,
						int conversion_posistion,
						va_list elements);
bool	handled_hex(const char **format,
						int *chars_printed,
						int conversion_posistion,
						va_list elements);

int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list elements);

#endif
