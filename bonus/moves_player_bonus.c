/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:28:16 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/30 13:16:27 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_player_to_up(t_var *p, int x, int y)
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
		set_img(x, y, p, 2);
		if (p->backup[y - 1][x] == 'E')
		{
			if (count_to_exit(p->backup) == 0)
			{
				ft_terminate(p, 0);
				exit (0);
			}
			p->exit = 1;
		}
		p->backup[y - 1][x] = '0';
		set_img(x, y - 1, p, 2);
		p->backup[y - 1][x] = 'P';
		set_img(x, y - 1, p, 2);
		print_moves(p, 1);
	}
}

void	move_player_to_right(t_var *p, int x, int y)
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
		set_img(x, y, p, 2);
		if (p->backup[y][x + 1] == 'E')
		{
			if (count_to_exit(p->backup) == 0)
			{
				ft_terminate(p, 0);
				exit (0);
			}
			p->exit = 1;
		}
		p->backup[y][x + 1] = '0';
		set_img(x + 1, y, p, 2);
		p->backup[y][x + 1] = 'P';
		set_img(x + 1, y, p, 0);
		print_moves(p, 1);
	}
}

void	move_player_to_left(t_var *p, int x, int y)
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
		set_img(x, y, p, 2);
		if (p->backup[y][x -1] == 'E')
		{
			if (count_to_exit(p->backup) == 0)
			{
				ft_terminate(p, 0);
				exit (0);
			}
			p->exit = 1;
		}
		p->backup[y][x - 1] = '0';
		set_img(x - 1, y, p, 2);
		p->backup[y][x - 1] = 'P';
		set_img(x - 1, y, p, 1);
		print_moves(p, 1);
	}
}

void	move_player_to_down(t_var *p, int x, int y)
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
		set_img(x, y, p, 2);
		if (p->backup[y + 1][x] == 'E')
		{
			if (count_to_exit(p->backup) == 0)
			{
				ft_terminate(p, 0);
				exit (0);
			}
			p->exit = 1;
		}
		p->backup[y + 1][x] = '0';
		set_img(x, y + 1, p, 2);
		p->backup[y + 1][x] = 'P';
		set_img(x, y + 1, p, 2);
		print_moves(p, 1);
	}
}

void	key_func(struct mlx_key_data keys, void *param)
{
	t_var	*p;

	p = (t_var *)param;
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
		ft_terminate(p, 1);
		exit(1);
	}
}
