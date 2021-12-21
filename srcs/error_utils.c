/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:25:27 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/21 23:53:53 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_f_n_l_line(char *line, t_error *error)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '1' || line[i] == '\n'))
			error->closed++;
		i++;
	}
}

void	check_inner_line(char *line, t_error *error)
{
	int i;

	i = 0;
	if (!(line[0] == '1'))
		error->square++;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1')
			i++;
		if (line[i] == 'E')
			error->ex++;
		if (line[i] == 'P')
			error->player++;
		if (line[i] == 'C')
			error->collectible++;
		else
			error->full++;
		i++;
	}
	if (line[i - 2] != '1')
		error->square++;
	if (ft_strlen(line) != error->size)
		error->square++;
}

void	error_message_map(t_error *error)
{
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

}
