/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:58:18 by myukang           #+#    #+#             */
/*   Updated: 2022/04/27 22:07:40 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	call_error_map(char	**splited)
{
	ft_printf("that map file is not a fdf map\n");
	ft_printf("please insert valid map file");
	free_split(splited);
	exit(1);
}

void	call_error_ac(void)
{
	ft_printf("please insert map name\n");
	ft_printf("./fdf [mapfile.fdf]\n");
	exit(1);
}
