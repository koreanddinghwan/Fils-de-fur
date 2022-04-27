/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:58:18 by myukang           #+#    #+#             */
/*   Updated: 2022/04/28 04:16:29 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	call_error_pixelalloc(t_dlst **pixel_list)
{
	ft_dlst_clear(pixel_list, free);
	ft_printf("Pixel Allocation Error\n");
	exit(1);
}

void	call_error_map(void)
{
	ft_printf("that map file is not a fdf map\n");
	ft_printf("please insert valid map file\n");
	exit(1);
}

void	call_error_ac(void)
{
	ft_printf("please insert map name\n");
	ft_printf("./fdf [mapfile.fdf]\n");
	exit(1);
}
