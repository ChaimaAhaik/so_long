/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:21:51 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/30 13:19:00 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# define HEIGTH 2560
# define WIDTH 1280

# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct dimensions
{
	int		x;
	int		h;
	int		w;
	int		fd;
	int		exit;
	int		moves;
	mlx_t	*mlx;
	char	**ptr;
	void	*param;
	void	*img[8];
	char	**backup;
	void	*texture[8];
}			t_var;

int			ft_printf(const char *format, ...);
void		free_all(char **ptr);
void		flood_fill(char **matrice, unsigned int x, unsigned int y);
int			parsing(char *s, int y, int x);
size_t		ft_strlen(const char *str);
char		*ft_strdup(char *str);
char		*ft_strchr(char *str, int c);
int			ft_strcmp(char *dest, char *src);
char		*ft_strjoin(char *sttc, char *buff);
char		*get_next_line(int fd);
int			length(int fd);
int			lenx(int fd);
int			count(char c, int fd);
char		**fill(int size, int fd);
char		*ft_strrchr(const char *s, int c);
int			open_file(char *s, int *fd);
int			check_for_input(char *s);
int			checks(char *p, int x, int j, int y);
int			length(int fd);
int			lenx(int fd);
int			check_for_fill(t_var *p);
int			count_c(char *matrice);
void		player_position(char **matrice, int *x, int *y);
void		imgs_loop(int y, int x, t_var *p);
void		key_func(struct mlx_key_data keys, void *p);
void		move_player_to_left(t_var *p, int x, int y);
void		move_player_to_right(t_var *p, int x, int y);
void		move_player_to_down(t_var *p, int x, int y);
void		move_player_to_up(t_var *p, int x, int y);
void		set_img(int x, int y, t_var *p, int direction);
int			count_to_exit(char **matrice);
void		img_inis(t_var *p);
void		var_inis(t_var *p);
void		exit_func(void *param);
void		ft_terminate(t_var *p, int n);
void		check_img_texture(t_var *p);
char		*ft_itoa(int n);
void		print_moves(t_var *p, int c);

#endif