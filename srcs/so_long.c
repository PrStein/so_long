/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:03:47 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/25 19:58:15 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_move(t_root *global)
{
	if (global->move > 0)
	{
		ft_putstr("You moved ");
		ft_putnbr_fd(global->move, 1);
		if (global->move == 1)
			ft_putstr(" time\n");
		else
			ft_putstr(" times\n");
	}
}

void	ft_error_arg(int ac)
{
	if (ac < 2)
		ft_putstr_fd("Missing argument\n", 2);
	if (ac > 2)
		ft_putstr_fd("Too many arguments\n", 2);
}

static int	key_print(int key, t_root *global)
{
	choose_move(key, global);
	return (0);
}

void	manage_mlx(t_root *global, t_error *error)
{
	init_root(global, error);
	global->mlx = mlx_init();
	global->mlx_win = mlx_new_window(global->mlx, global->width
			* global->size, global->height * global->size, "so_long");
	find_img(global);
	mlx_hook(global->mlx_win, 17, 0, ft_exit, global);
	mlx_key_hook(global->mlx_win, key_print, global);
	mlx_loop_hook(global->mlx, draw, global);
	mlx_loop(global->mlx);
}

int	main(int ac, char **av)
{
	t_root	global;
	t_error	error;

	if (ac == 2)
	{
		global.map = check_map(av, &global, &error);
		manage_mlx(&global, &error);
		ft_free(global.map);
	}
	if (ac != 2)
		ft_error_arg(ac);
}
