/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:45:57 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/24 22:53:30 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_player_sprite(t_root *d, t_img *tile)
{
	int	x_scale;
	int	y_scale;

	x_scale = (float)d->draw.x_s * ((float)tile->width / 64);
	y_scale = (float)d->draw.y_s * ((float)tile->height / 64);
	if (tile->addr[(x_scale * tile->bpp >> 3) + (y_scale * tile->line_l)] == 0
		&& tile->addr[(x_scale * tile->bpp >> 3) + 1 + (y_scale * tile->line_l)]
		== 0
		&& tile->addr[(x_scale * tile->bpp >> 3) + 2 + (y_scale * tile->line_l)]
		== 0)
		return ;
	d->display.addr[((d->draw.x_s + (d->pos.x * 64)) * d->display.bpp >> 3)
		+ ((d->draw.y_s + (d->pos.y * 64)) * d->display.line_l)]
		= tile->addr[(x_scale * tile->bpp >> 3) + (y_scale * tile->line_l)];
	d->display.addr[((d->draw.x_s + (d->pos.x * 64)) * d->display.bpp >> 3) + 1
		+ ((d->draw.y_s + (d->pos.y * 64)) * d->display.line_l)]
		= tile->addr[(x_scale * tile->bpp >> 3) + 1 + (y_scale * tile->line_l)];
	d->display.addr[((d->draw.x_s + (d->pos.x * 64)) * d->display.bpp >> 3) + 2
		+ ((d->draw.y_s + (d->pos.y * 64)) * d->display.line_l)]
		= tile->addr[(x_scale * tile->bpp >> 3) + 2 + (y_scale * tile->line_l)];
}

void	draw_sprite(t_root *d, t_img *tile)
{
	int	x_scale;
	int	y_scale;

	x_scale = (float)d->draw.x_s * ((float)tile->width / 64);
	y_scale = (float)d->draw.y_s * ((float)tile->height / 64);
	if (tile->addr[(x_scale * tile->bpp >> 3) + (y_scale * tile->line_l)] == 0
		&& tile->addr[(x_scale * tile->bpp >> 3) + 1 + (y_scale * tile->line_l)]
		== 0
		&& tile->addr[(x_scale * tile->bpp >> 3) + 2 + (y_scale * tile->line_l)]
		== 0)
		return ;
	d->display.addr[((d->draw.x_s + (d->draw.x_t * 64)) * d->display.bpp >> 3)
		+ ((d->draw.y_s + (d->draw.y_t * 64)) * d->display.line_l)]
		= tile->addr[(x_scale * tile->bpp >> 3) + (y_scale * tile->line_l)];
	d->display.addr[((d->draw.x_s + (d->draw.x_t * 64)) * d->display.bpp >> 3)
		+ 1 + ((d->draw.y_s + (d->draw.y_t * 64)) * d->display.line_l)]
		= tile->addr[(x_scale * tile->bpp >> 3) + 1 + (y_scale * tile->line_l)];
	d->display.addr[((d->draw.x_s + (d->draw.x_t * 64)) * d->display.bpp >> 3)
		+ 2 + ((d->draw.y_s + (d->draw.y_t * 64)) * d->display.line_l)]
		= tile->addr[(x_scale * tile->bpp >> 3) + 2 + (y_scale * tile->line_l)];
}

void	draw_tile(t_root *d, t_img *tile)
{
	int	x_scale;
	int	y_scale;

	x_scale = (float)d->draw.x_s * ((float)tile->width / 64);
	y_scale = (float)d->draw.y_s * ((float)tile->height / 64);
	d->display.addr[((d->draw.x_s + (d->draw.x_t * 64)) * d->display.bpp >> 3)
		+ ((d->draw.y_s + (d->draw.y_t * 64)) * d->display.line_l)]
		= tile->addr[(x_scale * tile->bpp >> 3) + (y_scale * tile->line_l)];
	d->display.addr[((d->draw.x_s + (d->draw.x_t * 64)) * d->display.bpp >> 3)
		+ 1 + ((d->draw.y_s + (d->draw.y_t * 64)) * d->display.line_l)]
		= tile->addr[(x_scale * tile->bpp >> 3) + 1 + (y_scale * tile->line_l)];
	d->display.addr[((d->draw.x_s + (d->draw.x_t * 64)) * d->display.bpp >> 3)
		+ 2 + ((d->draw.y_s + (d->draw.y_t * 64)) * d->display.line_l)]
		= tile->addr[(x_scale * tile->bpp >> 3) + 2 + (y_scale * tile->line_l)];
}
