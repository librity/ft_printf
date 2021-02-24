/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m@student.42sp.org.br <lpaulo-m>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 03:07:41 by lpaulo-m@st       #+#    #+#             */
/*   Updated: 2021/02/24 17:58:24 by lpaulo-m@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "printf.h"

void example4(void);

int main(void)
{
	printf("---------------------\n");
	example4();
	printf("---------------------\n");
}

void example4(void)
{
	printf("          '012345679123456'\n");
	printf("%%s:       '%s'\n", "Hello, world!");
	printf("%%15s:     '%15s'\n", "Hello, world!");
	printf("%%.10s:    '%.10s'\n", "Hello, world!");
	printf("%%-10s:    '%-10s'\n", "Hello, world!");
	printf("%%-15s:    '%-15s'\n", "Hello, world!");
	printf("%%.15s:    '%.15s'\n", "Hello, world!");
	printf("%%15.10s:  '%15.10s'\n", "Hello, world!");
	printf("%%-15.10s: '%-15.10s'\n", "Hello, world!");
}
