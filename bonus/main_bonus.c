/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:02:08 by cahaik            #+#    #+#             */
/*   Updated: 2024/07/05 13:57:54 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_img(int i, int j, t_var *p, int direction)
{
	if (p->backup[j][i] == '1')
		mlx_image_to_window(p->mlx, p->img[1], i * 64, j * 64);
	else if (p->backup[j][i] == 'C')
		mlx_image_to_window(p->mlx, p->img[3], i * 64, j * 64);
	else if (p->backup[j][i] == 'P')
	{
		if (direction == 0)
			mlx_image_to_window(p->mlx, p->img[5], i * 64, j * 64);
		else if (direction == 1)
			mlx_image_to_window(p->mlx, p->img[6], i * 64, j * 64);
		else
			mlx_image_to_window(p->mlx, p->img[4], i * 64, j * 64);
	}
	else if (p->backup[j][i] == 'E')
		mlx_image_to_window(p->mlx, p->img[2], i * 64, j * 64);
	else if (p->backup[j][i] == '0')
		mlx_image_to_window(p->mlx, p->img[0], i * 64, j * 64);
}

void	imgs_loop(int y, int x, t_var *p)
{
	int	i;
	int	j;

	j = 0;
	while (j < y && p->backup[j])
	{
		i = 0;
		while (i < x && p->backup[j][i])
		{
			set_img(i, j, p, 2);
			i++;
		}
		j++;
	}
}

void	print_moves(t_var *p, int c)
{
	char	*ptr;

	if (c == 0)
	{
		mlx_image_to_window(p->mlx, p->img[7], 0, 0);
		mlx_put_string(p->mlx, "Moves:", 20, 20);
		ptr = ft_itoa(0);
		mlx_put_string(p->mlx, ptr, 80, 20);
	}
	else
	{
		p->moves++;
		mlx_image_to_window(p->mlx, p->img[7], 0, 0);
		mlx_put_string(p->mlx, "Moves:", 20, 20);
		ptr = ft_itoa(p->moves);
		mlx_put_string(p->mlx, ptr, 80, 20);
	}
	free(ptr);
}

void	fill_ground(t_var *p)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < p->h * 64)
	{
		i = 0;
		while (i < p->w * 64)
		{
			mlx_image_to_window(p->mlx, p->img[0], i, j);
			i = 64 + i;
		}
		j = j + 64;
	}
	imgs_loop(p->h, p->w, p);
	mlx_close_hook(p->mlx, exit_func, p);
	print_moves(p, 0);
	mlx_key_hook(p->mlx, key_func, p);
	mlx_loop(p->mlx);
}

int	main(int ac, char **av)
{
	t_var	p;

	var_inis(&p);
	if (ac == 2)
	{
		if (ft_strcmp(".ber", ft_strrchr(av[1], '.')) != 0)
			return (write(2, "Error\ninvalid map : map name wrong\n", 35), 1);
		p.h = length(open_file(av[1], &(p.fd)));
		p.w = lenx(open_file(av[1], &(p.fd)));
		if (parsing(av[1], p.h, p.w) != 0)
			return (1);
		p.backup = fill(p.h, open_file(av[1], &(p.fd)));
		p.ptr = fill(p.h, open_file(av[1], &(p.fd)));
		player_position(p.ptr, &(p.fd), &(p.x));
		check_for_fill(&p);
	}
	else
		return (write(2, "Error\nARGC != 2\n", 16), 1);
	p.mlx = mlx_init(p.w * 64, p.h * 64, "so_long", false);
	img_inis(&p);
	fill_ground(&p);
	return (0);
}
