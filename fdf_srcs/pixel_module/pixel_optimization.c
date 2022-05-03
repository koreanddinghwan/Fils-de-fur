/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_optimization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:57:45 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 15:24:26 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_optimization(t_dlst **pixel_list)
{
	t_dlst	*cur_pixel_list;
	t_pixel	*cur_pixel;
	int		calculed_x;
	int		calculed_y;
	int		z_per_len_for_x;
	int		z_per_len_for_y;

	z_per_len_for_x = DEFAULT_Z_PIXEL_PER_LEN;
	z_per_len_for_y = DEFAULT_Z_PIXEL_PER_LEN;
	cur_pixel_list = *pixel_list;
	while (1)
	{
		while (cur_pixel_list)
		{
			cur_pixel = (t_pixel *)(cur_pixel_list->content);
			calculed_x = cur_pixel->x_in_window * z_per_len_for_x;
			calculed_y = cur_pixel->y_in_window * z_per_len_for_y;
			if (calculed_x >= 5120 || calculed_y >= 2880)
			{
				if (calculed_x >= 5120)
					z_per_len_for_x--;
				if (calculed_y >= 2880)
					z_per_len_for_y--;
				cur_pixel_list = *pixel_list;
				break ;
			}
			cur_pixel->x_printing_win = calculed_x;
			cur_pixel->y_printing_win = calculed_y;
			cur_pixel_list = cur_pixel_list->next;
		}
		if (!cur_pixel_list)
			break ;
		if (z_per_len_for_y < 0 || z_per_len_for_y < 0)
		{	
			call_error_free_list("Too large Map\n", pixel_list);
			break ;
		}
	}
} 
