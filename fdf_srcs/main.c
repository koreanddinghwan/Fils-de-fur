/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:50:11 by myukang           #+#    #+#             */
/*   Updated: 2022/04/27 22:07:39 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int main(int ac, char **av)
{
	if (ac != 2)
		call_error_ac();
	else if (ac == 2)
	{
		if (validate_file_name(av[1]))
			fils_de_fer(av[1]);
		else
			
	}
	exit(1);
}
