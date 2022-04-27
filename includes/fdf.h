/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:48:29 by myukang           #+#    #+#             */
/*   Updated: 2022/04/27 22:07:38 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "get_next_line.h"
#include "../minilibx/mlx.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

typedef struct	s_window
{
	int	x;  //window x축 길이
	int	y;	//window y축 길이
} t_window;

# define	DEFAULT_WINDOW_X	300
# define	DEFAULT_WINDOW_Y	300

# define	DEFAULT_COLOR		0xFFFFFF


void	fils_de_fer(char *av);



//tools

void	call_error_ac(void);
int		validate_file_name(char *path);
void	free_split(char **splited);

#endif
