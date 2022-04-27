/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:48:29 by myukang           #+#    #+#             */
/*   Updated: 2022/04/28 04:54:24 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "./get_next_line.h"
#include "../minilibx/mlx.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


# define	DEFAULT_WINDOW_X			300
# define	DEFAULT_WINDOW_Y			300
# define	DEFAULT_COLOR				0xFFFFFF
# define	DEFAULT_Z_PIXEL_PER_LEN		10

typedef struct	s_window
{
	int	x;  //window x축 길이
	int	y;	//window y축 길이
} t_window;

typedef	struct	s_pixel
{
	int	map_x;
	int	map_y;
	int	window_x;
	int	window_y;
	int	window_z;
	int	color;
} t_pixel;

void	fils_de_fer(char *av);
void	get_map_list(char	*path, t_dlst **line_list);

//tools
void	call_error_pixelalloc(t_dlst **pixel_list);
void	call_error_map(void);
void	call_error_ac(void);
void	free_split(char **splited);
int		validate_file(char *path);


//print_any
void	print_list_str(t_dlst *a);


#endif
