/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:34:40 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/23 21:57:40 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_root *global)
{
	int		i;

	i = 0;
	while (i < global->column)
	{
		free(global->map[i]);
		i++;
	}
	free(global->map);
}

void	free_tex(t_root *global)
{
	if (global->wall.loaded == true)
		mlx_destroy_image(global->mlx, global->wall.img);
	if (global->path.loaded == true)
		mlx_destroy_image(global->mlx, global->path.img);
	if (global->player.loaded == true)
		mlx_destroy_image(global->mlx, global->player.img);
	if (global->collectible.loaded == true)
		mlx_destroy_image(global->mlx, global->collectible.img);
	if (global->exit.loaded == true)
		mlx_destroy_image(global->mlx, global->exit.img);
}

int	ft_exit(t_root *global)
{
	if (global->map_loaded == true)
		free_map(global);
	free_tex(global);
	if (global->display.loaded == true)
		mlx_destroy_image(global->mlx, global->display.img);
	if (global->loaded == true)
		mlx_destroy_window(global->mlx, global->mlx_win);
	// free(global);
	exit(1);
}

void	ft_error(t_root *global, char *err_msg)
{
	printf("%s\n", err_msg);
	ft_exit(global);
}
