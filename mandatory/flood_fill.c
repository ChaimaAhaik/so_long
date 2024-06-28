/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:33:50 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/28 12:04:30 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void flood_fill(char **matrice, unsigned int x, unsigned int y)
{
	if (matrice[x][y] == '1' || matrice[x][y] == '*')
		return ;
	matrice[x][y] = '*';
	flood_fill(matrice, x + 1, y);
	flood_fill(matrice, x - 1, y);
	flood_fill(matrice, x, y + 1);
	flood_fill(matrice, x, y - 1);
}

int count_c(char *matrice)
{
	int i;

	i = 0;
	while (matrice[i])
	{
		if (matrice[i] == 'C' || matrice[i] == 'P' || matrice[i] == 'E')
			return (1);
		i++;
	}
	return (0);
}

int check_for_fill(var_t *p)
{
	int i;

	i = 0;
	flood_fill(p->ptr, p->x, p->fd);
	while(p->ptr[i])
	{
		if (count_c(p->ptr[i]) == 1)
		{
			free_all(p->ptr);
			free_all(p->backup);
			write(2, "Error\nmap invalid : problem of invalid path (E,C,P) != (0, 0, 0)\n",67);
			exit (1);
		}
		i++;
	}
	free_all(p->ptr);
	return (0);
}

