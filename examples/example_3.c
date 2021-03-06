/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 03:07:41 by lpaulo-m@st       #+#    #+#             */
/*   Updated: 2021/03/04 17:24:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "printf.h"

void example1(void);

int main(void)
{
	printf("---------------------\n");
	example1();
	printf("---------------------\n");
}

void example1(void)
{
	int first_int, second_int;
	float first_float, second_float;
	double first_double = 42.42;

	first_int = 15;
	second_int = first_int / 2;
	printf("int:    '%d'\n", second_int);
	ft_printf("int:    '%d'\n", second_int);
	printf("------------------------");

	printf("int:    '%3d'\n", second_int);
	ft_printf("int:    '%3d'\n", second_int);
	printf("------------------------");

	printf("int:    '%03d'\n", second_int);
	ft_printf("int:    '%03d'\n", second_int);
	printf("------------------------");


	first_float = 15.3;
	second_float = first_float / 3;
	printf("float:  '%3.2f'\n", second_float);
	ft_printf("float:  '%3.2f'\n", second_float);
	printf("------------------------");


	first_float = 15.365;
	second_float = first_float / 9;
	printf("float:  '%3.2f'\n", second_float);
	ft_printf("float:  '%3.2f'\n", second_float);
	printf("------------------------");

	printf("float:  '%3.3f'\n", second_float);
	ft_printf("float:  '%3.3f'\n", second_float);
	printf("------------------------");

	printf("float:  '%06.2f'\n", second_float);
	ft_printf("float:  '%06.2f'\n", second_float);
	printf("------------------------");

	printf("float:  '%2f'\n", second_float);
	ft_printf("float:  '%2f'\n", second_float);
	printf("------------------------");

	printf("float:  '%f'\n", second_float);
	ft_printf("float:  '%f'\n", second_float);
	printf("------------------------");


	printf("double: '%e'\n", first_double);
	ft_printf("double: '%e'\n", first_double);
	printf("------------------------");

}
