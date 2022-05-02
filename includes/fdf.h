/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:48:29 by myukang           #+#    #+#             */
/*   Updated: 2022/05/02 00:58:28 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "./get_next_line.h"
#include "../mlx/mlx.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

# define	DEFAULT_WINDOW_X			300
# define	DEFAULT_WINDOW_Y			300
# define	DEFAULT_COLOR				0xFFFFFF
# define	DEFAULT_Z_PIXEL_PER_LEN		10

typedef	struct	s_pixel
{
	int		map_x;
	int		map_y;
	int		map_z;
	int		x_in_window;
	int		y_in_window;
	int		color;
} t_pixel;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_dlst	**pixel_list;
} t_mlx;

void	fils_de_fer(char *av);
void	get_map_list(char	*path, t_dlst **line_list);

//pixel_module
void	init_pixel(t_dlst *line_list, t_dlst **line_list_addr, t_dlst **pixel_list_addr);
int		pixel_color_parser(char *str);
void	pixel_correction(t_dlst **pixel_list);
//mlx_mod
void	mod_mlx(t_dlst **pixel_list);
void	bresenham_pixel_put(t_pixel *p1, t_pixel *p2, t_mlx *mlx);

//tools
void	call_error_free_list(char *str, t_dlst **pixel_list);
void	call_error(char	*str);
void	free_split(char **splited);
double	get_x(int x, int y, int angle);
int	get_y(int x, int y, int z);
//map_check_module
int		extension_check_module(char *path);
void	square_check_module(t_dlst *line_list, t_dlst **origin);
//print_any
void	print_list_str(t_dlst *a);
void	print_pixel_data(t_dlst *a);

#endif
