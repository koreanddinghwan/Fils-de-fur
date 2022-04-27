/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:50:27 by myukang           #+#    #+#             */
/*   Updated: 2022/04/28 02:32:20 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	validate_file_name(char *path)
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

int	validate_file(char *path)
{
	if (!validate_file_name(path))
		call_error_map();
	return (1);
}
