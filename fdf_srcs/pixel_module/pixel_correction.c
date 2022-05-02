/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_correction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:28:45 by myukang           #+#    #+#             */
/*   Updated: 2022/05/02 14:01:43 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_min_x(t_dlst *pixel_list)
{
	int	rtn;
	int	x;

	rtn = 0;
	while (pixel_list)
	{
		x = ((t_pixel *)pixel_list->content)->x_in_window;
		if (x < rtn && x < 0)
			rtn = ((t_pixel *)pixel_list->content)->x_in_window;
		pixel_list = pixel_list->next;
	}
	return (rtn);
}

static int	get_min_y(t_dlst *pixel_list)
{
	int	rtn;
	int	y;

	rtn = 0;
	while (pixel_list)
	{
		y = ((t_pixel *)pixel_list->content)->y_in_window;
		if (y < rtn && y < 0)
			rtn = ((t_pixel *)pixel_list->content)->y_in_window;
		pixel_list = pixel_list->next;
	}
	return (rtn);
}

static void	correction(int min_x, int min_y, t_pixel *pixel)
{
	pixel->x_in_window += abs(min_x);
	pixel->y_in_window += abs(min_y);
}

void	pixel_correction(t_dlst **pixel_list)
{
	int		min_x;
	int		min_y;
	t_dlst	*pixel_cur;
	
	min_x = get_min_x(*pixel_list);
	min_y = get_min_y(*pixel_list);
	pixel_cur = *pixel_list;
	while (pixel_cur)
	{
		correction(min_x, min_y, (t_pixel *)pixel_cur->content);
		pixel_cur = pixel_cur->next;
	}
}
