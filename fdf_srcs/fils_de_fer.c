/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:11:05 by myukang           #+#    #+#             */
/*   Updated: 2022/04/27 21:02:43 by myukang          ###   ########.fr       */
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
	int	fd;

	fd = open(path, O_RDONLY);
	if (errno)
	{
		perror(strerror(errno));
		exit(1);
	}

	close(fd);

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
	mlx_loop(mlx_ptr);
}
