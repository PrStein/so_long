/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:06:33 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/21 23:32:44 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_init_error(t_error *error)
{
	error->closed = 0;
	error->square = 0;
	error->size = 0;
	error->player = 0;
	error->collectible = 0;
	error->ex = 0;
	error->full = 0;
}
