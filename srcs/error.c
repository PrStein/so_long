/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:13:02 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/22 00:05:44 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	reverse_comp(char *s1, char *s2)
{
	int size_s1;
	int size_s2;

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

void	isafile(char **av, t_error *error)
{
	int fd;
	char *line;
	int test;

	fd = open(av[1], O_RDONLY);
	test = read(fd, line, 1);
	printf("test = %d\n", test);
	line = get_next_line(fd);

	printf("%s", line);

	error->size = ft_strlen(line);
	check_f_n_l_line(line, error);
	printf("\n%d\n", error->size);
	printf("\n[%d]\n", error->closed);

	while ((line = get_next_line(fd)) != NULL)
	{
		check_inner_line(line, error);
		printf("\n{%d}\n", error->square);
		printf("%s", line);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
	free(line);
	close(fd);
}

int	check_map(char **av)
{
	t_error error;

	if (reverse_comp(av[1], ".ber"))
		return (1);
	ft_init_error(&error);
	isafile(av, &error);
	error_message_map(&error);

	return (0);
}
