/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:11:05 by myukang           #+#    #+#             */
/*   Updated: 2022/04/30 22:07:18 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void fils_de_fer(char *path)
{
	t_dlst	*line_list;

	line_list = 0;
	get_map_list(path, &line_list);
	print_list_str(line_list);
	square_check_module(line_list, &line_list);
}
