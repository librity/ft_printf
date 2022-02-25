/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_clamped_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:16:46 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/25 11:40:57 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** Maps a double that varies between a range into a target range.
** If the result lies outside the target
** it returns the closest limit, min or max.
*/
double	ft_map_clamped_d(t_map_d args)
{
	double	mapped;

	mapped = ft_map_d(args);
	if (args.start2 < args.stop2)
		return (ft_clamp_d(mapped, args.start2, args.stop2));
	return (ft_clamp_d(mapped, args.stop2, args.start2));
}
