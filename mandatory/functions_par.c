/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_par.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:52:43 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/06 17:49:01 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int checks(char *p, int x, int j, int y)
{
	int i;

	i = 0;
	if (j == 0 || j == y - 1)
	{
		while (p[i])
		{
			if (p[i] != '1')
				break ;
			i++;
		}
	}
	else
	{
		while (p[i] == '1' || p[i] == '0' || p[i] == 'P' || p[i] == 'C' || p[i] == 'E')
			i++;
	}
	if (i != x || p[0] != '1' || p[i - 1] != '1')
	{
		return (write(2, "moxkil f size awla l characters\n",33),1);
	}
	return (0);
}

int count(char c, int fd)
{
	int i;
	int tmp;
	char *p;
	
	tmp = 0;
	while ((p = get_next_line(fd)))
	{
		i = 0;
		while ((unsigned int)i < (ft_strlen(p) - 1) && p[i])
		{
			if (p[i] == c)
				tmp++;
			i++;
		}
		free(p);
	}
	close(fd);
	return (tmp);
}

int lenx(int fd)
{
	int size;
	char *p;
	
	size = 0;
	p = get_next_line(fd);
	if (!p)
		return (0);
	size = ft_strlen(p);
	free(p);
	close (fd);
	return (size - 1);
}

int length(int fd)
{
	int len;
	char *p;

	len = 0;
	while ((p = get_next_line(fd)) != NULL)
	{
		len++;
		free(p);
	}
	close(fd);
	return (len);
}

int check_for_input(char *s)
{
	int fd;
	
	fd = 0;
	if (count('E', open_file(s, &fd)) != 1 || count('C', open_file(s, &fd)) < 1 || count ('P', open_file(s, &fd)) != 1)
		return (write(2, "moxkil f number dyal E awla C awla P\n",38), 1);
	return (0);
}
