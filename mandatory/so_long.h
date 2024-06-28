/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:21:51 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/28 12:06:02 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

#define HEIGTH	2560
#define WIDTH	1280

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include "../MLX42/include/MLX42/MLX42.h"

typedef struct dimensions
{
	int x;
	int h;
	int w;
	int fd;
	int exit;
	int moves;
	void *img;
	mlx_t *mlx;
	void *texture;
	char **backup;
	char **ptr;
}					var_t;		

void	free_all(char **ptr);
void	flood_fill(char **matrice, unsigned int x, unsigned int y);
int		parsing(char *s, int y, int x);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str, int c);
int		ft_strcmp(char *dest, char *src);
char	*ft_strjoin(char *sttc, char *buff);
char	*get_next_line(int fd);
int		length(int fd);
int		lenx(int fd);
int		count(char c, int fd);
char	**fill(int size, int fd);
int		ft_printf(const char *format, ...);
char	*ft_strrchr(const char *s, int c);
int		open_file(char *s, int *fd);
int		check_for_input(char *s);
int		checks(char *p, int x, int j, int y);
int		length(int fd);
int		lenx(int fd);
int		check_for_fill(var_t *p);
int		count_c(char *matrice);
void	player_position(char **matrice, int *x, int *y);
void	imgs_loop(char **backup, int y, int x, mlx_t *mlx);
void	key_func(struct mlx_key_data keys, void *p);
void	move_player_to_left(var_t *p, int x, int y);
void	move_player_to_right(var_t *p, int x, int y);
void	move_player_to_down(var_t *p, int x, int y);
void	move_player_to_up(var_t *p, int x, int y);
void	set_img(char c, int i, int j, mlx_t *mlx, int direction);
int		count_to_exit(char **matrice);
#endif