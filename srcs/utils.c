/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:09:28 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/25 00:24:09 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_tex(t_root *global, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(global->mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
		ft_error(global, "Error\nProblem with a texture path!\n");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_l, &tex->endian);
	if (!tex->addr)
		ft_error(global, "Error\nCan't get texture address!\n");
	tex->loaded = true;
}

void	find_img(t_root *global)
{
	global->display.img = mlx_new_image(global->mlx, global->width * 64,
			global->height * 64);
	global->display.addr = mlx_get_data_addr(global->display.img,
			&global->display.bpp, &global->display.line_l, &global->display.endian);
	global->display.loaded = true;
	get_tex(global, &global->wall, "textures/squarewall.xpm");
	get_tex(global, &global->path, "textures/greypath.xpm");
	get_tex(global, &global->player, "textures/ghost.xpm");
	get_tex(global, &global->collectible, "textures/treasure.xpm");
	get_tex(global, &global->exit, "textures/door.xpm");
}
