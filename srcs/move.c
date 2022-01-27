/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:45:45 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/25 19:56:25 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	choose_move(int key, t_root *global)
{
	find_position(global);
	if (key == 13)
		move_up(global);
	if (key == 0)
		move_left(global);
	if (key == 1)
		move_down(global);
	if (key == 2)
		move_right(global);
	if (key == 53)
		ft_exit(global);
}

void	move_up(t_root *global)
{
	if (global->map[global->x - 1][global->y] != '1')
	{
		if (global->map[global->x - 1][global->y] == 'C')
			global->collectible.n -= 1;
		if (global->map[global->x - 1][global->y] == 'E')
		{
			if (global->collectible.n == 0)
			{
				ft_putstr("Well played\n");
				ft_exit(global);
			}
			else
				return ;
		}
		global->map[global->x - 1][global->y] = 'P';
		global->map[global->x][global->y] = '0';
		global->move++;
		print_move(global);
	}
}

void	move_left(t_root *global)
{
	if (global->map[global->x][global->y - 1] != '1')
	{
		if (global->map[global->x][global->y - 1] == 'C')
			global->collectible.n -= 1;
		if (global->map[global->x][global->y - 1] == 'E')
		{
			if (global->collectible.n == 0)
			{
				ft_putstr("Well played\n");
				ft_exit(global);
			}
			else
				return ;
		}
		global->map[global->x][global->y - 1] = 'P';
		global->map[global->x][global->y] = '0';
		global->move++;
		print_move(global);
	}
}

void	move_down(t_root *global)
{
	if (global->map[global->x + 1][global->y] != '1')
	{
		if (global->map[global->x + 1][global->y] == 'C')
			global->collectible.n -= 1;
		if (global->map[global->x + 1][global->y] == 'E')
		{
			if (global->collectible.n == 0)
			{
				ft_putstr("Well played\n");
				ft_exit(global);
			}
			else
				return ;
		}
		global->map[global->x + 1][global->y] = 'P';
		global->map[global->x][global->y] = '0';
		global->move++;
		print_move(global);
	}
}

void	move_right(t_root *global)
{
	if (global->map[global->x][global->y + 1] != '1')
	{
		if (global->map[global->x][global->y + 1] == 'C')
			global->collectible.n -= 1;
		if (global->map[global->x][global->y + 1] == 'E')
		{
			if (global->collectible.n == 0)
			{
				ft_putstr("Well played\n");
				ft_exit(global);
			}
			else
				return ;
		}
		global->map[global->x][global->y + 1] = 'P';
		global->map[global->x][global->y] = '0';
		global->move++;
		print_move(global);
	}
}
