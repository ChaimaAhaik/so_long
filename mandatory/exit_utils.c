/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 11:32:03 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/30 09:56:57 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_img_texture(t_var *p)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (p->texture[i] == NULL)
		{
			write (2, "Error\nFailed to load : pic name wrong\n", 38);
			free_all(p->backup);
			mlx_terminate(p->mlx);
			exit (1);
		}
		i++;
	}
}

void	free_all(char **ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	ft_terminate(t_var *p, int n)
{
	free_all(p->backup);
	mlx_terminate(p->mlx);
	if (n == 1)
		ft_printf("Game Over You lose 💀");
	else
		ft_printf("Game Over You Won 🏆");
}

int	count_to_exit(char **matrice)
{
	int	i;
	int	j;
	int	counter;

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

void	exit_func(void *param)
{
	t_var	*p;

	p = (t_var *)param;
	ft_printf("You closed the window 😒");
	free_all(p->backup);
	mlx_terminate(p->mlx);
	exit (0);
}
