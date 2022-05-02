/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:00:28 by myukang           #+#    #+#             */
/*   Updated: 2022/05/01 18:15:03 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	get_index(char c)
{
	char	*cap;
	char	*small;
	int		i;

	small = "0123456789abcdef";
	cap = "0123456789ABCDEF";
	i = 0;
	if (c >= 65 && c <= 90)
	{
		while (cap[i])
		{
			if (c == cap[i++])
				return (i);
		}
	}
	else
	{
		while (small[i])
		{
			if (c == small[i++])
				return (i);
		}
	}
	return (0);
}

static int	find_hex_str(char c)
{
	if (c >= 48 && c <= 57)
		return (c - 48);
	else
		return (get_index(c));
}

static int	convert_hex_ascii(char *str)
{
	int		rtn;

	rtn = 0;
	while (!ft_isspace(*str) && *str)
	{
		rtn = 16 * rtn + find_hex_str(*str);
		str++;
	}
	return (rtn);
}

int	pixel_color_parser(char *str)
{
	while (*str != 'x')
		str++;
	str++;
	return (convert_hex_ascii(str));
}
