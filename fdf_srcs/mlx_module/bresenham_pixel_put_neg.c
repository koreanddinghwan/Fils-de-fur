/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_pixel_put_neg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:21:20 by myukang           #+#    #+#             */
/*   Updated: 2022/05/02 21:40:41 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	upper_incline(int xy[3][3], t_mlx *mlx, int pi, int recur)
{
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, xy[1][0], xy[1][1], xy[2][2]);
	if (recur == 0)
		upper_incline(xy, mlx, 2 * xy[0][0] - xy[0][1], 1);
	if ((xy[1][0] == xy[2][0]) && (xy[1][1] == xy[2][1]))
		return ;
	if (pi >= 0)
	{
		xy[1][0]--;
		xy[1][1]++;
		pi += 2 * (xy[0][0] - xy[0][1]);
	}
	else
	{
		xy[1][1]++;
		pi += 2 * xy[0][0];
	}
	upper_incline(xy, mlx, pi, 1);
}

void	under_incline(int xy[3][3], t_mlx *mlx, int pi, int recur)
{
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, xy[1][0], xy[1][1], xy[2][2]);
	if (recur == 0)
		under_incline(xy, mlx, 2 * xy[0][1] - xy[0][0], 1);
	if ((xy[1][0] == xy[2][0]) && (xy[1][1] == xy[2][1]))
		return ;
	if (pi >= 0)
	{
		xy[1][0]--;
		xy[1][1]++;
		pi += 2 * (xy[0][1] - xy[0][0]);
	}
	else
	{
		xy[1][0]--;
		pi += 2 * xy[0][1];
	}
	under_incline(xy, mlx, pi, 1);
}

void	bresenham_pixel_put_neg(t_pixel *p1, t_pixel *p2, t_mlx *mlx, int color)
{
	int	xy_set[3][3];

	xy_set[0][0] = abs(p2->x_in_window - p1->x_in_window);
	xy_set[0][1] = abs(p2->y_in_window - p1->y_in_window);
	xy_set[1][0] = p1->x_in_window;
	xy_set[1][1] = p1->y_in_window;
	xy_set[2][0] = p2->x_in_window;
	xy_set[2][1] = p2->y_in_window;
	xy_set[2][2] = color;	
	if (xy_set[0][0] < xy_set[0][1])
		upper_incline(xy_set, mlx, 0, 0);
	else
		under_incline(xy_set, mlx, 0, 0);
}
