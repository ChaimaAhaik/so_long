NAME = so_long

CC = cc -Werror -Wall -Wextra 

CFLAGS = -Wall -Wextra -Werror

MLX = MLX42/build/libmlx42.a -I"../../MLX42/include/MLX42/MLX42.h" -lglfw -L"/Users/cahaik/.brew/opt/glfw/lib/"

SRC = mandatory/main.c mandatory/check_av.c mandatory/functions_par.c mandatory/get_next_line.c \
	mandatory/libft_func.c mandatory/ft_printf.c mandatory/flood_fill.c mandatory/get_utils.c \

OBJ = $(SRC:.c=.o)

all :$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all