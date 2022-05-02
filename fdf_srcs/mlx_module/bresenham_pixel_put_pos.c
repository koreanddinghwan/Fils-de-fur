/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_pixel_put_down.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:27:38 by myukang           #+#    #+#             */
/*   Updated: 2022/05/02 18:20:46 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	_upper_incline(int xy[3][3], t_mlx *mlx, int pi, int recur)
{
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, xy[1][0], xy[1][1], xy[2][2]);
	if (recur == 0)
		_upper_incline(xy, mlx, 2 * xy[0][0] - xy[0][1], 1);
	if ((xy[1][0] == xy[2][0]) && (xy[1][1] == xy[2][1]))
		return ;
	if (pi >= 0)
	{
		xy[1][0]++;
		xy[1][1]++;
		pi += 2 * (xy[0][0] - xy[0][1]);
	}
	else
	{
		xy[1][1]++;
		pi += 2 * xy[0][0];
	}
	_upper_incline(xy, mlx, pi, 1);
}

void	_under_incline(int xy[3][3], t_mlx *mlx, int pi, int recur)
{
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, xy[1][0], xy[1][1], xy[2][2]);
	if (recur == 0)
		_under_incline(xy, mlx, 2 * xy[0][1] - xy[0][0], 1);
	if ((xy[1][0] == xy[2][0]) && (xy[1][1] == xy[2][1]))
		return ;
	if (pi >= 0)
	{
		xy[1][0]++;
		xy[1][1]++;
		pi += 2 * (xy[0][1] - xy[0][0]);
	}
	else
	{
		xy[1][0]++;
		pi += 2 * xy[0][1];
	}
	_under_incline(xy, mlx, pi, 1);
}

void	bresenham_pixel_put_pos(t_pixel *p1, t_pixel *p2, t_mlx *mlx, int color)
{
	int	xy_set[3][3];

	xy_set[0][0] = p2->x_in_window - p1->x_in_window;
	xy_set[0][1] = p2->y_in_window - p1->y_in_window;
	xy_set[1][0] = p1->x_in_window;
	xy_set[1][1] = p1->y_in_window;
	xy_set[2][0] = p2->x_in_window;
	xy_set[2][1] = p2->y_in_window;
	xy_set[2][2] = color;	
	if (xy_set[0][0] < xy_set[0][1])
		_upper_incline(xy_set, mlx, 0, 0);
	else
		_under_incline(xy_set, mlx, 0, 0);
}
