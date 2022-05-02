/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:12:34 by myukang           #+#    #+#             */
/*   Updated: 2022/05/02 14:42:08 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

static int	get_max_x(t_dlst *pixel_list)
{
	int	x;

	x = ((t_pixel *)pixel_list->content)->x_in_window;
	while (pixel_list)
	{
		if (x < ((t_pixel *)pixel_list->content)->x_in_window)
			x = ((t_pixel *)pixel_list->content)->x_in_window;
		pixel_list = pixel_list->next;
	}
	return (x);
}

static int	get_max_y(t_dlst *pixel_list)
{
	int	y;

	y = ((t_pixel *)pixel_list->content)->y_in_window;
	while (pixel_list)
	{
		if (y < ((t_pixel *)pixel_list->content)->y_in_window)
			y = ((t_pixel *)pixel_list->content)->y_in_window;
		pixel_list = pixel_list->next;
	}
	return (y);
}

void	open_window(t_mlx *mlx)
{
	int	max_x;
	int	max_y;

	max_x = get_max_x(*(mlx->pixel_list));
	max_y = get_max_y(*(mlx->pixel_list));
	if (max_x + 1 > 5120 || max_y + 1 > 2880)
		call_error_free_list("Too big screen\n", mlx->pixel_list);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, max_x + 1, max_y + 1, "fdf");
}
