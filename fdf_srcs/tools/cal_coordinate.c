/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_coordinate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 03:18:51 by myukang           #+#    #+#             */
/*   Updated: 2022/05/02 14:26:43 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

double	get_x(int x, int y, int angle)
{
	double	a;

	a = tan(angle * M_PI / 180);
	return (((x - y) * a) * 10);
}

int	get_y(int x, int y, int z)
{
	return (((x + y) - 2 * z) * 10);
}
