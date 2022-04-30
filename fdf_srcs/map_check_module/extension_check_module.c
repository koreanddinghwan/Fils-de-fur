/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check_module.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:50:27 by myukang           #+#    #+#             */
/*   Updated: 2022/04/30 20:50:36 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	validate_file_extension(char *path)
{
	char	**splited;
	int		i;

	splited = ft_split(path, '.');
	i = 0;
	while (splited[i])
		i++;
	i--;
	if (ft_strncmp("fdf", splited[i], ft_strlen(splited[i])))
	{
		free_split(splited);
		return (0);
	}
	free_split(splited);
	return (1);
}

int	extension_check_module(char *path)
{
	if (!validate_file_extension(path))
		call_error("that map file is not a fdf map\nplease insert valid map file\n");
	return (1);
}
