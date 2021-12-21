/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:03:47 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/21 15:46:42 by sadjigui         ###   ########.fr       */
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
	if (ac == 2)
	{
		if(check_map(av) == 1)
		{
			ft_putstr_fd("Error map\n", 2);
		}
	}
	if (ac != 2)
		ft_error_arg(ac);
}
