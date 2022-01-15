#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <sys/types.h>

typedef enum e_bool {
	true,
	false
}				t_bool;

typedef struct s_error{
	unsigned int closed;
	unsigned int square;
	size_t size;
	unsigned int player;
	unsigned int collectible;
	unsigned int full;
	unsigned int ex;
}			t_error;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		height;
	int		width;
	int		line_l;
	int		endian;
	int		loaded;
}				t_img;

typedef struct s_root{
	t_bool loaded;
	t_bool map_loaded;
	int size;
	void *mlx;
	void *mlx_win;
	char **map;
	int width;
	unsigned int height;
	t_img display;
	t_img player;
	t_img collectible;
	t_img exit;
	t_img path;
	t_img wall;
}			t_root;

int	main(int ac, char **av);
int	reverse_comp(char *s1, char *s2);

void	check_f_n_l_line(char *line, t_error *error);
void	ft_error_arg(int ac);
void	ft_init_error(t_error *error);
void	check_inner_line(char *line, t_error *error);
void	error_message_map(t_error *error, char **map);
void	check_zero_one(char **split, t_error *error);
void	ft_free(char **map);
void	manage_mlx(t_root *global);
void	size_window(t_root *global);
void	init_root(t_root *global);
void	find_img(t_root *global);
void	ft_error(t_root *global, char *err_msg);
void	ft_exit(t_root *global);
void	free_tex(t_root *global);
void	free_map(t_root *global);

char	**check_map(char **av);
char	**isafile(char **av, t_error *error);

#endif
