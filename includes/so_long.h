#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <sys/types.h>

typedef struct s_error{
	int closed;
	int square;
	int size;
	int player;
	int collectible;
	int full;
	int ex;
}			t_error;

int	main(int ac, char **av);
int	check_map(char **av);
int	reverse_comp(char *s1, char *s2);

void	check_f_n_l_line(char *line, t_error *error);
void	ft_error_arg(int ac);
void	isafile(char **av, t_error *error);
void	ft_init_error(t_error *error);
void	check_inner_line(char *line, t_error *error);
void	error_message_map(t_error *error);

#endif
