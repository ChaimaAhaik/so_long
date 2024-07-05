/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_par_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:52:43 by cahaik            #+#    #+#             */
/*   Updated: 2024/07/04 16:51:38 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	checks(char *p, int x, int j, int y)
{
	int	i;

	i = 0;
	if (j == 0 || j == y - 1)
	{
		while (p[i])
		{
			if (p[i] != '1')
			{
				if (j == y - 1 && p[i] != '\n')
					return (write (2, "Error\nInvalid Character\n", 24), 1);
				break ;
			}
			i++;
		}
	}
	else
	{
		if (help_for_check(p, &i) == 1)
			return (1);
	}
	if (i != x || p[0] != '1' || p[i - 1] != '1')
		return (write(2, "Error\nsize of line or invalid character\n", 40), 1);
	return (0);
}

int	count(char c, int fd)
{
	int		i;
	int		tmp;
	char	*p;

	tmp = 0;
	p = get_next_line(fd);
	while (p)
	{
		i = 0;
		while ((unsigned int)i < (ft_strlen(p) - 1) && p[i])
		{
			if (p[i] == c)
				tmp++;
			i++;
		}
		free(p);
		p = get_next_line(fd);
	}
	close(fd);
	return (tmp);
}

int	lenx(int fd)
{
	int		size;
	char	*p;

	size = 0;
	p = get_next_line(fd);
	if (!p)
		return (0);
	size = ft_strlen(p);
	free(p);
	close (fd);
	return (size - 1);
}

int	length(int fd)
{
	int		len;
	char	*p;

	len = 0;
	p = get_next_line(fd);
	while (p)
	{
		len++;
		free(p);
		p = get_next_line(fd);
	}
	close(fd);
	return (len);
}

int	check_for_input(char *s)
{
	int	fd;

	fd = 0;
	if (count('E', open_file(s, &fd)) != 1 
		|| count('C', open_file(s, &fd)) < 1 
		|| count ('P', open_file(s, &fd)) != 1)
		return (write(2, "Error\ninvalid map : number of E, C or P\n", 40), 1);
	return (0);
}
