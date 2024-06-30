NAME = so_long

BONUS = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = MLX42/build/libmlx42.a -I"../../MLX42/include/MLX42/MLX42.h" -lglfw -L"/Users/cahaik/.brew/opt/glfw/lib/"

SRC = mandatory/main.c mandatory/check_av.c mandatory/functions_par.c mandatory/get_next_line.c \
	mandatory/libft_func.c mandatory/ft_printf.c mandatory/flood_fill.c mandatory/get_utils.c  \
	mandatory/moves_player.c mandatory/exit_utils.c \

BONUS_SRC = bonus/main_bonus.c bonus/check_av_bonus.c bonus/functions_par_bonus.c bonus/get_next_line_bonus.c \
	bonus/libft_func_bonus.c bonus/ft_printf_bonus.c bonus/flood_fill_bonus.c bonus/get_utils_bonus.c  \
	bonus/moves_player_bonus.c bonus/exit_utils_bonus.c \

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all :$(NAME)

bonus : $(BONUS)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS)  $(MLX) $(OBJ) -o $(NAME)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(MLX) $(BONUS_OBJ) -o $(BONUS)

mandatory/%.o : mandatory/%.c mandatory/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all