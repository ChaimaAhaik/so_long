/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:09:14 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/30 10:23:16 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	open_file(char *s, int *fd)
{
	*fd = open(s, O_RDONLY);
	return (*fd);
}

static int	ov_size(int x, int y, int w_heigth, int w_width)
{
	if ((y * w_width) > WIDTH || (x * w_heigth) > HEIGTH)
		return (write(2, "Error\ninvalid map : error in size\n", 34), 1);
	return (0);
}

int	parsing(char *s, int y, int x)
{
	int		fd;
	int		i;
	char	*p;

	i = 0;
	fd = 0;
	if (ov_size(x, y, 64, 64) == 1 || check_for_input(s) == 1) 
		return (1);
	open_file(s, &fd);
	p = get_next_line(fd);
	while (i < y && p)
	{
		if (checks(p, x, i, y) == 1)
			return (free(p), 1);
		else
			free(p);
		p = get_next_line(fd);
		i++;
	}
	return (close(fd), 0);
}
