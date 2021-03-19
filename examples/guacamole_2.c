/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guacamole_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:40:07 by mchardin          #+#    #+#             */
/*   Updated: 2021/03/19 00:09:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{

	printf("\n--------------\n");
	// printf(" --- Return : %d\n", printf("%-192.131%"));
	printf("%%                                                                                                                                                                                                --- Return : 192\n");
	printf(" --- Return : %d\n", ft_printf("%-192.131%"));

	printf("\n--------------\n");
	// printf(" --- Return : %d\n", printf("%-70.193x%-140c%168c%026.51%%0125.119X", 1102840003u, -50, -17, 3721437512u));
	printf("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000041bc00c3                                                                                                                                                                                                                                                                                                                  0000000000000000000000000%      000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000DDD0A148 --- Return : 652\n");
	printf(" --- Return : %d\n", ft_printf("%-70.193x%-140c%168c%026.51%%0125.119X", 1102840003u, -50, -17, 3721437512u));

	printf("\n--------------\n");
	ft_printf("|0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000041bc00c3|\n|                                                                                                                                           |\n|                                                                                                                                                                       |\n|0000000000000000000000000%|\n|      000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000DDD0A148| --- Return : 665\n");
	ft_printf(" --- Return : %d\n", ft_printf("|%-70.193x|\n|%-140c|\n|%168c|\n|%026.51%|\n|%0125.119X|", 1102840003u, -50, -17, 3721437512u));

	printf("\n--------------\n");
	printf("0000000000000000000000000%% --- Return : 26\n");
	ft_printf(" --- Return : %d\n", ft_printf("%026.51%"));

	printf("\n--------------\n");
	printf("%%                          --- Return : 26\n");
	ft_printf(" --- Return : %d\n", ft_printf("%0-26.51%"));

	printf("\n--------------\n");
	printf("                         a --- Return : 26\n");
	ft_printf(" --- Return : %d\n", ft_printf("%026.51c", 'a'));

	printf("\n--------------\n");
	printf("a                          --- Return : 26\n");
	ft_printf(" --- Return : %d\n", ft_printf("%0-26.51c", 'a'));
}
