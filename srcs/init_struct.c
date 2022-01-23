/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:06:33 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/23 16:27:31 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	size_window(t_root *global)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(global->map[0][j])
		j++;
	global->width = j;
	while (global->map[i])
		i++;
	global->height = i;
}

void	init_root(t_root *global, t_error *error)
{
	size_window(global);
	global->size = 64;
	global->collectible.n = error->collectible;
}

void	ft_init_error(t_error *error, t_root *global)
{
	error->closed = 0;
	error->square = 0;
	error->size = 0;
	error->player = 0;
	error->collectible = 0;
	error->ex = 0;
	error->full = 0;
	global->row = 0;
	global->column = 0;
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}
