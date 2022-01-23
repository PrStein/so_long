/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:45:37 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/23 17:01:52 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	first_display(t_global *g)
{
	int		j;
	int		i;

	i = -1;
	while (++i < global->row)
	{
		j = -1;
		while (++j < g->column)
			select_texture(g, i, j);
	}
	mlx_put_image_to_window(global->mlx, global->win,
		g->window.img.img, 0, 0);
	if (g->end == 1)
	{
		ft_putstr("Good Game !\n");
		close_cub(g);
	}
	return (0);
}
