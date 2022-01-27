/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:45:37 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/25 19:35:53 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_player(t_root *global)
{
	global->draw.y_s = 0;
	while (global->draw.y_s < 64)
	{
		global->draw.x_s = 0;
		while (global->draw.x_s < 64)
		{
			draw_player_sprite(global, &global->player);
			global->draw.x_s++;
		}
		global->draw.y_s++;
	}
}

void	draw_sprites(t_root *global, char tile)
{
	global->draw.y_s = 0;
	while (global->draw.y_s < 64)
	{
		global->draw.x_s = 0;
		while (global->draw.x_s < 64)
		{
			if (tile == 'C')
				draw_sprite(global, &global->collectible);
			else if (tile == 'E')
				draw_sprite(global, &global->exit);
			if (tile == 'P')
				draw_sprite(global, &global->player);
			global->draw.x_s++;
		}
		global->draw.y_s++;
	}
}

void	draw_tiles(t_root *global, char tile)
{
	global->draw.y_s = 0;
	while (global->draw.y_s < 64)
	{
		global->draw.x_s = 0;
		while (global->draw.x_s < 64)
		{
			if (tile == '1')
				draw_tile(global, &global->wall);
			else
				draw_tile(global, &global->path);
			global->draw.x_s++;
		}
		global->draw.y_s++;
	}
}

int	draw(t_root *global)
{
	global->draw.y_t = 0;
	while (global->draw.y_t < global->height)
	{
		global->draw.x_t = 0;
		while (global->draw.x_t < global->width)
		{
			draw_tiles(global, global->map[global->draw.y_t][global->draw.x_t]);
			draw_sprites(global, global->map[global->draw.y_t][global->draw.x_t]);
			// draw_player(global, global->map[global->draw.y_t][global->draw.x_t]);
			global->draw.x_t++;
		}
		global->draw.y_t++;
	}
	mlx_put_image_to_window(global->mlx, global->mlx_win,
		global->display.img, 0, 0);
	return (0);
}
