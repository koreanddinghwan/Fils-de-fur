/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:11:05 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 15:18:38 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void fils_de_fer(char *path)
{
	t_dlst	*line_list;
	t_dlst	*pixel_list;

	line_list = 0;
	pixel_list = 0;
	get_map_list(path, &line_list);
	square_check_module(line_list, &line_list);
	init_pixel(line_list, &line_list, &pixel_list);
	pixel_correction(&pixel_list);
	printf("pixel correction\n");
	print_pixel_data(pixel_list);
	pixel_optimization(&pixel_list);
	printf("pixel optimization\n");
	print_pixel_data(pixel_list);
	ft_dlst_clear(&line_list, free);
	mod_mlx(&pixel_list);
}
