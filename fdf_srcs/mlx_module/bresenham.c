/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 00:10:08 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 00:25:24 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_pixel *start, t_pixel *end, t_mlx *mlx, int color)
{
	int	addx;
	int	addy;
	int	counter = 0;
	int	dx;
	int	dy;

	dx = end->x_in_window - start->x_in_window;
	dy = end->y_in_window - start->y_in_window;
	int x = start->x_in_window;
	int	y = start->y_in_window;
	int	i = 0;
	if (dx < 0)
	{
		addx = -1;
		dx = -dx;
	}
	else
		addx = 1;
	if (dy < 0)
	{
		addy = -1;
		dy = -dy;
	}
	else
		addy = 1;
	if (dx >= dy)
	{
		i = 0;
		while (i < dx)
		{
			x += addx;
			counter += dy;
			if (counter >= dx)
			{
				y += addy;
				counter -= dx;
			}
			i++;
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, color);
		}
	}
	else
	{
		i = 0;
		while (i < dy)
		{
			y += addy;
			counter += dx;
			if (counter >= dy)
			{
				x += addx;
				counter -= dy;
			}
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, color);
			i++;
		}
	}
}
