/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_check_module.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:52:12 by myukang           #+#    #+#             */
/*   Updated: 2022/05/01 01:23:48 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	get_num(t_dlst	*line_list)
{
	int		i;
	char	**splited;

	i = 0;
	splited = ft_split((char *)line_list->content, ' ');
	while (splited[i])
		i++;
	free_split(splited);
	return (i);
}

void	square_check_module(t_dlst *line_list, t_dlst **origin)
{
	int	num;

	num = get_num(line_list);
	while (line_list)
	{
		line_list = line_list->next;
		if (!line_list)
			break ;
		if (num != get_num(line_list))
			return (call_error_free_list("Invalid map, give me rectangle map!\n", origin));
	}
}
