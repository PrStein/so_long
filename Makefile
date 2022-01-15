NAME = so_long

CC = clang

FLAGS    = -Wall -Wextra -Werror -g

DEL = /bin/rm -f

SRCS =	./srcs/so_long.c\
		./srcs/error.c\
		./gnl/get_next_line.c\
		./gnl/get_next_line_utils.c\
		./srcs/init_struct.c\
		./srcs/error_utils.c\
		./srcs/utils.c\
		./srcs/exit.c\

SRCS_O    = ${SRCS:.c=.o}

all: $(NAME)

LIBC    = ar -rcs

%.o: %.c
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${SRCS_O}
			make bonus -C ./libft/
		 $(CC) $(FLAGS) $(SRCS_O) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -L ./libft/ -lft

fclean: clean
		$(DEL) $(NAME)
		make fclean -C ./libft/

clean:
		$(DEL) $(SRCS_O)
		make clean -C ./libft/

re: fclean all
