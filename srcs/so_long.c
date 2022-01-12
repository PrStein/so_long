/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:03:47 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/11 20:28:48 by sadjigui         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	char	**map = NULL;

	if (ac == 2)
	{
		map = check_map(av);
		ft_free(map);
	}
	if (ac != 2)
		ft_error_arg(ac);
}
