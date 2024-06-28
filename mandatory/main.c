/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:02:08 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/28 12:09:57 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **fill(int size, int fd)
{
	int i;
	char *line;
	char **matrice;
	
	i = 0;
	matrice = malloc((size + 1) * sizeof(char *));
	if (!matrice)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		matrice[i] = ft_strdup(line);
		free(line);
		i++;
	}
	matrice[i] = NULL;
	close (fd);
	return (matrice);
}

void player_position(char **matrice, int *x, int *y)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (matrice[i])
	{
		j = 0;
		while (matrice[i][j])
		{
			if (matrice[i][j] == 'P')
			{
				*x = j;
				*y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}
void free_all(char **ptr)
{
	int i;

	i = 0;
	while(ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
int count_to_exit(char **matrice)
{
	int i;
	int j;
	int counter;

	j = 0;
	counter = 0;
	while (matrice && matrice[j])
	{
		i = 0;
		while (matrice[j][i])
		{
			if (matrice[j][i] == 'C')
				counter++;
			i++;
		}
		j++;
	}
	return (counter);
}

void set_img(char c, int i, int j, mlx_t *mlx, int direction)
{
	i = i * 64;
	j = j * 64;
	if (c == '1')
		mlx_image_to_window(mlx, mlx_texture_to_image(mlx, mlx_load_png("mandatory/images/wall.png")), i, j);
	else if (c == 'C')
		mlx_image_to_window(mlx, mlx_texture_to_image(mlx, mlx_load_png("mandatory/images/carrot.png")), i, j);
	else if (c == 'P')
	{
		if (direction == 0)
			mlx_image_to_window(mlx, mlx_texture_to_image(mlx, mlx_load_png("mandatory/images/right.png")), i, j);
		else if (direction == 1)
			mlx_image_to_window(mlx, mlx_texture_to_image(mlx, mlx_load_png("mandatory/images/left.png")), i, j);
		else
			mlx_image_to_window(mlx, mlx_texture_to_image(mlx, mlx_load_png("mandatory/images/direct.png")), i, j);
	}
	else if (c == 'E')
		mlx_image_to_window(mlx, mlx_texture_to_image(mlx, mlx_load_png("mandatory/images/door.png")), i, j);
	else if (c == '0')
		mlx_image_to_window(mlx, mlx_texture_to_image(mlx, mlx_load_png("mandatory/images/grass.png")), i, j);
}

void move_player_to_left(var_t *p, int x, int y)
{
	if (p->backup[y][x - 1] != '1')
	{
		if (p->exit == 1)
		{
			p->backup[y][x] = 'E';
			p->exit = 0;
		}
		else
			p->backup[y][x] = '0';
		set_img(p->backup[y][x], x, y, p->mlx, 2);
		x = x - 1;
		if (p->backup[y][x] == 'E')
		{
			if (count_to_exit(p->backup) == 0)
			{
				free_all(p->backup);
				mlx_terminate(p->mlx);
				ft_printf("Game Over You Won 🏆");
				exit (0);
			}
			p->exit = 1;
		}
		p->backup[y][x] = 'P';
		set_img('0', x, y, p->mlx, 2);
		set_img(p->backup[y][x], x, y, p->mlx, 1);
		ft_printf("moves = %d\n",++(p->moves));
	}
}

void move_player_to_right(var_t *p, int x, int y)
{
	if (p->backup[y][x + 1] != '1')
	{
		if (p->exit == 1)
		{
			p->backup[y][x] = 'E';
			p->exit = 0;
		}
		else
			p->backup[y][x] = '0';
		set_img(p->backup[y][x], x, y, p->mlx, 2);
		x = x + 1;
		if (p->backup[y][x] == 'E')
		{
			if (count_to_exit(p->backup) == 0)
			{
				free_all(p->backup);
				mlx_terminate(p->mlx);
				ft_printf("Game Over You Won 🏆");
				exit (0);
			}
			p->exit = 1;
		}
		p->backup[y][x] = 'P';
		set_img('0', x, y, p->mlx, 2);
		set_img(p->backup[y][x], x, y, p->mlx, 0);
		ft_printf("moves = %d\n",++(p->moves));
	}
}

void move_player_to_down(var_t *p, int x, int y)
{
	if (p->backup[y + 1][x] != '1')
	{
		if (p->exit == 1)
		{
			p->backup[y][x] = 'E';
			p->exit = 0;
		}
		else
			p->backup[y][x] = '0';
		set_img(p->backup[y][x], x, y, p->mlx, 2);
		y = y + 1;
		if (p->backup[y][x] == 'E')
		{
			if (count_to_exit(p->backup) == 0)
			{
				free_all(p->backup);
				mlx_terminate(p->mlx);
				ft_printf("Game Over You Won 🏆");
				exit (0);
			}
			p->exit = 1;
		}
		p->backup[y][x] = 'P';
		set_img('0', x, y, p->mlx, 2);
		set_img(p->backup[y][x], x, y, p->mlx, 2);
		ft_printf("moves = %d\n",++(p->moves));
	}
}

void move_player_to_up(var_t *p, int x, int y)
{
	if (p->backup[y - 1][x] != '1')
	{
		if (p->exit == 1)
		{
			p->backup[y][x] = 'E';
			p->exit = 0;
		}
		else
			p->backup[y][x] = '0';
		set_img(p->backup[y][x], x, y, p->mlx, 2);
		y = y - 1;
		if (p->backup[y][x] == 'E')
		{
			if (count_to_exit(p->backup) == 0)
			{
				free_all(p->backup);
				mlx_terminate(p->mlx);
				ft_printf("Game Over You Won 🏆");
				exit (0);
			}
			p->exit = 1;
		}
		p->backup[y][x] = 'P';
		set_img('0', x, y, p->mlx, 2);
		set_img(p->backup[y][x], x, y, p->mlx, 2);
		ft_printf("moves = %d\n",++(p->moves));
	}
}

void key_func(struct mlx_key_data keys, void *param)
{
	var_t *p;
	
	p = (var_t *)param;
	player_position(p->backup, &(p->x), &(p->fd));
	if ((keys.key == 65 || keys.key == 263) && keys.action)
		move_player_to_left(p, p->x, p->fd);
	else if ((keys.key == 83 || keys.key == 264) && keys.action)
		move_player_to_down(p, p->x, p->fd);
	else if ((keys.key == 68 || keys.key == 262) && keys.action)
		move_player_to_right(p, p->x, p->fd);
	else if ((keys.key == 87 || keys.key == 265) && keys.action)
		move_player_to_up(p, p->x, p->fd);
	else if (keys.key == 256)
	{
		ft_printf("Game Over You lose 💀");
		free_all(p->backup);
		mlx_terminate(p->mlx);
		exit (1);
	}
}

void imgs_loop(char **backup, int y, int x, mlx_t *mlx)
{
	int i;
	int j;

	j = 0;
	while (j < y && backup[j])
	{
		i = 0;
		while(i < x && backup[j][i])
		{
			set_img(backup[j][i], i, j, mlx, 2);
			i++;
		}
		j++;
	}
}

void fill_ground(var_t *p)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j < p->h * 64)
	{
		i = 0;
		while (i < p->w * 64)
		{
			mlx_image_to_window(p->mlx, p->img, i, j);
			i = 64 + i;
		}
		j = j + 64;
	}
	imgs_loop (p->backup, p->h, p->w, p->mlx);
	mlx_key_hook(p->mlx, key_func, p);
	mlx_loop(p->mlx);
}

void initializer(var_t *p)
{
	p->x = 0;
	p->w = 0;
	p->h = 0;
	p->fd = 0;
	p->exit = 0;
	p->moves = 0;
	p->ptr = NULL;
	p->backup = NULL;
}

int main(int ac, char **av)
{
	var_t p;
	
	initializer(&p);
	if (ac == 2)
	{
		if(ft_strcmp(".ber", ft_strrchr(av[1], '.')) == 0)
		{
			p.h = length(open_file(av[1], &(p.fd)));
			p.w = lenx(open_file(av[1], &(p.fd)));
			if (parsing(av[1], p.h, p.w) == 0)
			{
				p.backup = fill(p.h, open_file(av[1], &(p.fd)));
				p.ptr = fill(p.h, open_file(av[1], &(p.fd)));
				player_position(p.ptr, &(p.fd), &(p.x));
			}
			else
				return (write(2, "Error\nmap invalid : error in parsing\n",39), 1);
		}
		else
			return (write(2, "Error\nmap invalid : map name wrong\n",37), 1);
	}
	else
		return (write(2, "Error\nARGC != 2\n",8), 1);
	p.mlx = mlx_init(p.w * 64, p.h * 64, "test", true);
	p.texture = mlx_load_png("mandatory/images/grass.png");
	p.img = mlx_texture_to_image(p.mlx, p.texture);
	fill_ground(&p);
	return (0);
}
