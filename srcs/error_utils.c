/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:25:27 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/25 15:28:23 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_f_n_l_line(char *line, t_error *error, t_root *global)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n')
			error->closed++;
		i++;
	}
	if (ft_strlen(line) != error->size)
		error->square++;
	global->row = i;
}

void	check_inner_line(char *line, t_error *error)
{
	int	i;

	i = 0;
	if (line[0] != '1')
		error->closed++;
	while (line[i + 1])
	{
		if (line[i] == '0' && line[i] == '1' && line[i] == '\n')
			i++;
		if (line[i] == 'E')
			error->ex++;
		else if (line[i] == 'P')
			error->player++;
		else if (line[i] == 'C')
			error->collectible++;
		else if (line[i] != 'C' && line[i] != 'P'
			&& line[i] != 'E' && line[i] != '0' && line[i] != '1')
			error->full++;
		i++;
	}
	if (line[i] != '1')
		error->closed++;
	if (ft_strlen(line) != error->size)
		error->square++;
}

void	error_message_map(t_error *error, char **map)
{
	if (error->closed != 0)
		ft_putstr_fd("Map is not closed\n", 2);
	if (error->square != 0)
		ft_putstr_fd("Map is not square\n", 2);
	if (error->ex <= 0)
		ft_putstr_fd("Missing exit\n", 2);
	if (error->collectible <= 0)
		ft_putstr_fd("Missing collectibles\n", 2);
	if (error->player > 1)
		ft_putstr_fd("Too many player\n", 2);
	if (error->player < 1)
		ft_putstr_fd("Missing player\n", 2);
	if (error->full != 0)
		ft_putstr_fd("Don't mess with the map boy\n", 2);
	if (error->closed != 0 || error->square != 0
		|| error->ex <= 0 || error->collectible <= 0
		|| error->player != 1 || error->full != 0)
	{
		ft_free(map);
		exit(1);
	}
}

void	check_zero_one(char **split, t_error *error, t_root *global)
{
	int	i;

	i = 0;
	check_f_n_l_line(split[0], error, global);
	i++;
	while (split[i + 1])
	{
		check_inner_line(split[i], error);
		i++;
	}
	check_f_n_l_line(split[i], error, global);
	global->column = i + 1;
}
