/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:11:05 by myukang           #+#    #+#             */
/*   Updated: 2022/04/28 04:54:23 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int desl_key(int key, void *param)
{
	ft_printf("param : %p, key : %d\n", (void *)param, key);
	return (0);
}

void fils_de_fer(char *path)
{
	t_dlst	*line_list;

	line_list = 0;
	get_map_list(path, &line_list);
	print_list_str(line_list);
	//1. 맵이 직사각형인지 확인

	//2. 맵의 인자가 공백으로 나눴을때는 숫자만 있는가
	//숫자만 있는게 아니면 콤마로 나누어서 왼쪽에 숫자, 오른쪽에 색상인가 확인
/*
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();

	win_ptr = mlx_new_window(mlx_ptr, DEFAULT_WINDOW_X, DEFAULT_WINDOW_Y, "mlx test");
	//
	int i = 0;

	while (i < 250)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, i, DEFAULT_COLOR);
		i++;
	}
	mlx_key_hook(win_ptr, desl_key, (void *)0);
	mlx_loop(mlx_ptr);*/
}
