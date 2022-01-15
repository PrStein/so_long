/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:03:47 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/15 16:08:00 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_arg(int ac)
{
	if (ac < 2)
		ft_putstr_fd("Missing argument\n", 2);
	if (ac > 2)
		ft_putstr_fd("Too many arguments\n", 2);
}

void	manage_mlx(t_root *global)
{
	init_root(global);
	global->mlx = mlx_init();
	global->mlx_win = mlx_new_window(global->mlx, global->width
		* global->size, global->height * global->size, "so_long");
	find_img(global);
	mlx_loop(global->mlx);
}

int	main(int ac, char **av)
{
	t_root global;

	if (ac == 2)
	{
		global.map = check_map(av);
		manage_mlx(&global);
		ft_free(global.map);
	}
	if (ac != 2)
		ft_error_arg(ac);
}
