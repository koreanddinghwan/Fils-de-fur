/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_any.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:43:58 by myukang           #+#    #+#             */
/*   Updated: 2022/04/28 04:54:24 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	print_list_str(t_dlst *a)
{
	char	*str;

	while (a)
	{
		str = (char *)a->content;
		ft_printf("%s", str);
		a = a->next;
	}
}
