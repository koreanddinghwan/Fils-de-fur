/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:45:20 by myukang           #+#    #+#             */
/*   Updated: 2022/05/02 20:10:10 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pixel	*find_right_pixel(t_dlst *cur, t_pixel *start)
{
	int		map_x;
	int		map_y;
	t_dlst	*next;

	map_x = start->map_x;
	map_y = start->map_y;
	next = cur->next;
	if (!next)
		return (0);
	if ((map_x + 1 == ((t_pixel *)next->content)->map_x) && (map_y == ((t_pixel *)next->content)->map_y))
		return ((t_pixel *)next->content);
	else
		return (0);
	return (0);
}

static t_pixel	*find_down_pixel(t_dlst *cur, t_pixel *start)
{
	int	map_x;
	int	map_y;

	map_x = start->map_x;
	map_y = start->map_y;
	while (cur && (((t_pixel *)cur->content)->map_x == map_x))
		cur = cur->next;
	if (!cur)
		return (0);
	if ((((t_pixel *)cur->content)->map_y == map_y + 1) && (((t_pixel *)cur->content)->map_x == map_x))
		return ((t_pixel *)cur->content);
	return (0);
}

static void	call_bresen(t_pixel	*start, t_pixel *dest, t_mlx *mlx)
{
	int	dx;
	int	dy;

	dx = dest->x_in_window - start->x_in_window;
	dy = dest->y_in_window - start->y_in_window;
	if (dx * dy > 0)
	{
		if (dx < 0)
			bresenham_pixel_put_pos(dest, start, mlx, dest->color);
		else
			bresenham_pixel_put_pos(start, dest, mlx, dest->color);
	}
	else
	{
		if (dx > 0)
			bresenham_pixel_put_neg(start, dest, mlx, dest->color);
		else
			bresenham_pixel_put_neg(dest, start, mlx, dest->color);
	}
}

void pixel_print(t_mlx *mlx)
{
	t_dlst	*cur;
	t_pixel	*start;
	t_pixel	*right;
	t_pixel	*down;

	cur = *(mlx->pixel_list);
	while (cur)
	{
		start = (t_pixel *)(cur->content);
		right = find_right_pixel(cur, start);
		down = find_down_pixel(cur, start);
		if (right)
			call_bresen(start, right, mlx);
		if (down)
			call_bresen(start, down, mlx);
		cur = cur->next;
	}
}
