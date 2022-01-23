/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:55:21 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/23 17:04:39 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void find_position(t_root *global)
{
	int x;
	int y;

	x = 0;
	while (global->map[x])
	{
		y = 0;
		while (global->map[x][y])
		{
			if (global->map[x][y] == 'P')
				break ;
			y++;
		}
		if (global->map[x][y] == 'P')
			break ;
		x++;
	}
	global->x = x;
	global->y = y;
}

// Hello from key_hook 13!
// Hello from key_hook 0!
// Hello from key_hook 1!
// Hello from key_hook 2!
// Echap is 53
