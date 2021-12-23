/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:25:27 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/23 18:21:57 by sadjigui         ###   ########.fr       */
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
	if (ft_strlen(line) != error->size)
		error->square++;
}

void	check_inner_line(char *line, t_error *error)
{
	int i;

	i = 0;
	if (!(line[0] == '1'))
		error->closed++;
	printf("let's go = ");
	while (line[i])
    {
        if (line[i] == 'E')
            error->ex++;
        else if (line[i] == 'P')
            error->player++;
        else if (line[i] == 'C')
            error->collectible++;
        else if (line[i] != '0' && line[i] != '1' && line[i] != '\n')
			i++;
	}
	if (!(line[i] == '1'))
		error->closed++;
	if (ft_strlen(line) != error->size)
		error->square++;
	printf("\n");
}

void	error_message_map(t_error *error)
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
	printf("full = %d\n", error->full);

}

void	check_zero_one(char **split, t_error *error)
{
	int i;

	i = 0;
	check_f_n_l_line(split[0], error);
	i++;
	while (split[i + 1])
	{
		check_inner_line(split[i], error);
		i++;
	}
	check_f_n_l_line(split[i], error);
	printf("--%d\n", error->closed);
	printf("--%s\n", split[0]);

}
