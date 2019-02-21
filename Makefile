NAME = wolf3d

SRCDIR = ./srcs/

SRCNAMES =	expose_hook.c \
 						ft_mlx.c \
     				get_grid.c \
   					get_map.c \
		     		get_perso.c \
						get_view.c \
						key_hook.c \
						main.c \
						utils.c\
						raycast.c\

INC = ./include/
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
OBJ = $(patsubst %.c,%.o, $(SRC))

LIBDIR = ./Libft/
LIBFT = ./Libft/libft.a
LIBINC = ./Libft/libft.h
LIB_MLX = minilibX/libmlx.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFLAGS = -lm -lmlx -L minilibx
MLXFLAGS = -framework OpenGL -framework Appkit
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft/
		@$(CC) $(CFLAGS) $(SANI) -o $(NAME) $(LIBFT) $(OBJ) $(LIBFLAGS) $(MLXFLAGS)
		@echo "\033[0;32m[OK] \033[0m\033[0;33m Compiling file:\033[0m " $@

clean:
	@make -C libft clean
	@echo "\033[0;32m[OK] \033[0m\033[0;33m :\033[0m " $@
	@/bin/rm -f $(OBJ)

fclean: clean
		@make -C libft fclean
		@echo "\033[0;32m[OK] \033[0m\033[0;33m :\033[0m " $@
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
