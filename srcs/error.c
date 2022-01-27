/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:49:14 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/25 20:16:55 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	reverse_comp(char *s1, char *s2)
{
	int	size_s1;
	int	size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	while (size_s2 >= 0)
	{
		if (!(s2[size_s2] == s1[size_s1]))
			return (1);
		size_s1--;
		size_s2--;
	}
	return (0);
}

char	**isafile(char **av, t_error *error, t_root *global)
{
	int		fd;
	char	*line;
	char	*str;
	char	*tmp;
	char	**split;

	fd = open(av[1], O_RDONLY);
	str = NULL;
	tmp = NULL;
	if (fd == - 1)
		exit(1);
	while ((line = get_next_line(fd)) != NULL)
	{
		tmp = ft_strjoin(str, line);
		if (str != NULL)
			free(str);
		str = tmp;
		free(line);
		line = NULL;
	}
	split = ft_split(str, '\n');
	free(line);
	free(str);
	close(fd);
	error->size = ft_strlen(split[0]);
	check_zero_one(split, error, global);
	return (split);
}

char	**check_map(char **av, t_root *global, t_error *error)
{
	char	**map;

	map = NULL;
	if (reverse_comp(av[1], ".ber") || (ft_strlen(av[1]) == ft_strlen(".ber")))
	{
		ft_putstr_fd("Error map", 2);
		exit(1);
	}
	ft_init_error(error, global);
	map = isafile(av, error, global);
	error_message_map(error, map);
	return (map);
}
