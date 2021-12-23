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
	char *str;
	char **split;
	int i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	// line = get_next_line(fd);
	str = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		str = ft_strjoin(str, line);
		free(line);
		line = NULL;
	}
	split = ft_split(str, '\n');
	free(line);
	close(fd);
	error->size = ft_strlen(split[0]);
	while (split[i])
		printf("-----%s\n", split[i++]);
	check_zero_one(split, error);
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
