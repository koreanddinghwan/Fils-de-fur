/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_pixel_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 00:07:08 by myukang           #+#    #+#             */
/*   Updated: 2022/05/02 00:55:03 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void	upper_incline(int *start, int *dest, int *cline, t_mlx *mlx)
{
	static int	recur;
	static int	bresen_num;

	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, start[0], start[1]);
	if (start[0] == dest[0] && start[1] == dest[1])
	{
		recur = 0;
		bresen_num = 0;
		return ;
	}
	if (recur == 0 && bresen_num == 0)
		bresen_num = 2 * cline[0] - cline[1];
	if (recur != 0 && bresen_num >= 0)
	{
		start[0]++;
		start[1]++;
		bresen_num = bresen_num + 2 * (cline[0] - cline[1]);
	}
	else if (recur != 0 && bresen_num < 0)
	{
		start[1]++;
		bresen_num = bresen_num + 2 cline[0];
	}
	recur++;
	upper_incline(start, dest, cline, mlx);
}

static void	under_incline(int *start_x_y, int *dest_x_y, int *cline_x_y, t_mlx *mlx)
{
	static int	recur;
	static int	bresen_num;

	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, start[0], start[1]);
	if (start[0] == dest[0] && start[1] == dest[1])
	{
		recur = 0;
		bresen_num = 0;
		return ;
	}
	if (recur == 0 && bresen_num == 0)
		bresen_num = 2 * cline[1] - cline[0];
	if (recur != 0 && bresen_num >= 0)
	{
		start[0]++;
		start[1]++;
		bresen_num = bresen_num + 2 * (cline[1] - cline[0]);
	}
	else if (recur != 0 && bresen_num < 0)
	{
		start[0]++;
		bresen_num = bresen_num + 2 cline[1];
	}
	recur++;
	under_incline(start, dest, cline, mlx);
}

void	bresenham_pixel_put(t_pixel *p1, t_pixel *p2, t_mlx *mlx)
{
	int	*cline_x_y;
	int	*start_x_y;
	int	*dest_x_y;

	cline_x_y = ft_calloc(2, sizeof(int));
	start_x_y = ft_calloc(2, sizeof(int));
	dest_x_y = ft_calloc(2, sizeof(int));
	if (!cline_x_y || !start_x_y || !dest_x_y)
		call_error_free_list("pixel_put_error\n", mlx->pixel_list);
	cline_x_y[0] = p2->x_in_window - p1->x_in_window;
	cline_x_y[1] = p2->y_in_window - p1->y_in_window;
	start_x_y[0] = p1->x_in_window;
	start_x_y[1] = p1->y_in_window;
	dest_x_y[0] = p2->x_in_window;
	dest_x_y[1] = p2->y_in_window;
	if (dx < dy)//기울기가 1보다 큼
		upper_incline(start_x_y, dest_x_y, cline_x_y, mlx);
	else//기울기가 1이하
		under_incline(start_x_y, dest_x_y, cline_x_y, mlx);
	free(start_x_y);
	free(dest_x_y);
	free(cline_x_y);
}
