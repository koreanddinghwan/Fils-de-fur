/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:50:27 by myukang           #+#    #+#             */
/*   Updated: 2022/04/27 22:07:37 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	validate_file_name(char *path)
{
	char	**splited;
	int		i;

	splited = ft_split(path, '.');
	i = 0;
	while (splited[i])
		i++;
	i--;
	if (!ft_strncmp("fdf", splited[i], ft_strlen(splited[i])))
	{
		free_split(splited);
		return (0);
	}

	return (1);
}
