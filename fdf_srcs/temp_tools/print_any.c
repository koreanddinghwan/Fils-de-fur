/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_any.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:43:58 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 15:16:11 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	print_list_str(t_dlst *a)
{
	char	*str;

	while (a)
	{
		str = (char *)a->content;
		ft_printf("%s", str);
		a = a->next;
	}
}

void	print_pixel_data(t_dlst *a)
{
	int	i;

	i = 0;
	while (a)
	{
		ft_printf("%d 번째 픽셀의 x%d\n", i, ((t_pixel *)a->content)->map_x);
		ft_printf("%d 번째 픽셀의 y%d\n", i, ((t_pixel *)a->content)->map_y);
		ft_printf("%d 번째 픽셀의 z%d\n", i, ((t_pixel *)a->content)->map_z);
		printf("%d 번째 픽셀의 color%x\n", i, ((t_pixel *)a->content)->color);
		printf("%d 번째 픽셀, x_in_window :  %f, y_in_window %f\n", i, ((t_pixel *)a->content)->x_in_window, ((t_pixel *)a->content)->y_in_window);
		printf("%d 번째 픽셀, x_printing_win :  %d, y_printing_win %d\n", i, ((t_pixel *)a->content)->x_printing_win, ((t_pixel *)a->content)->y_printing_win);
		a = a->next;
		i++;
	}

}
