/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:58:07 by sadjigui          #+#    #+#             */
/*   Updated: 2022/01/25 19:55:14 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	unsigned int	closed;
	unsigned int	square;
	size_t			size;
	unsigned int	player;
	unsigned int	collectible;
	unsigned int	full;
	unsigned int	ex;
}				t_error;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		height;
	int		width;
	int		line_l;
	int		endian;
	int		loaded;
	int		n;
}				t_img;

typedef struct s_draw {
	unsigned int	x_t;
	unsigned int	y_t;
	unsigned int	x_s;
	unsigned int	y_s;
}				t_draw;

typedef struct s_pos {
	int	x;
	int	y;
	int	left;
	int	right;
}				t_pos;

typedef struct s_root{
	t_bool			loaded;
	t_bool			map_loaded;
	int				size;
	void			*mlx;
	void			*mlx_win;
	char			**map;
	unsigned int	width;
	unsigned int	height;
	t_img			display;
	t_img			player;
	t_img			collectible;
	t_img			exit;
	t_img			path;
	t_img			wall;
	t_draw			draw;
	t_pos			pos;
	int				row;
	int				column;
	int				x;
	int				y;
	int				x_pxl;
	int				y_pxl;
	int				move;
}					t_root;

int		main(int ac, char **av);
int		reverse_comp(char *s1, char *s2);
int		ft_exit(t_root *global);
int		draw(t_root *global);

void	check_f_n_l_line(char *line, t_error *error, t_root *global);
void	ft_error_arg(int ac);
void	ft_init_error(t_error *error, t_root *global);
void	check_inner_line(char *line, t_error *error);
void	error_message_map(t_error *error, char **map);
void	check_zero_one(char **split, t_error *error, t_root *global);
void	ft_free(char **map);
void	manage_mlx(t_root *global, t_error *error);
void	size_window(t_root *global);
void	init_root(t_root *global, t_error *error);
void	find_img(t_root *global);
void	ft_error(t_root *global, char *err_msg);
void	free_tex(t_root *global);
void	free_map(t_root *global);
void	find_position(t_root *global);
void	choose_move(int key, t_root *global);
void	move_up(t_root *global);
void	move_left(t_root *global);
void	move_down(t_root *global);
void	move_right(t_root *global);
void	draw_tiles(t_root *global, char tile);
void	draw_sprites(t_root *global, char tile);
void	draw_player(t_root *global);
void	draw_tile(t_root *d, t_img *tile);
void	draw_sprite(t_root *d, t_img *tile);
void	draw_player_sprite(t_root *d, t_img *tile);
void	ft_free_str(char *str);
void	print_move(t_root *global);

char	**check_map(char **av, t_root *global, t_error *error);
char	**isafile(char **av, t_error *error, t_root *global);

#endif
