/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:29:02 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/30 12:20:12 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *dest, char *src)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (1);
	while (dest[i] || src[i])
	{
		if (!((unsigned char)dest[i] == (unsigned char)src[i]))
			return ((unsigned char)dest[i] - (unsigned char)src[i]);
		i++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*end;

	if (!s)
		return (NULL);
	end = (char *)s + ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (end >= s)
	{
		if ((unsigned char)*end == (unsigned char)c)
			return ((char *)end);
		end--;
	}
	return (NULL);
}

void	var_inis(t_var *p)
{
	p->x = 0;
	p->w = 0;
	p->h = 0;
	p->fd = 0;
	p->exit = 0;
	p->moves = 0;
	p->ptr = NULL;
	p->param = NULL;
	p->backup = NULL;
}

void	img_inis(t_var *p)
{
	p->texture[0] = mlx_load_png("bonus/textures/grass.png");
	p->texture[1] = mlx_load_png("bonus/textures/wall.png");
	p->texture[2] = mlx_load_png("bonus/textures/door.png");
	p->texture[3] = mlx_load_png("bonus/textures/carrot.png");
	p->texture[4] = mlx_load_png("bonus/textures/direct.png");
	p->texture[5] = mlx_load_png("bonus/textures/right.png");
	p->texture[6] = mlx_load_png("bonus/textures/left.png");
	p->texture[7] = mlx_load_png("bonus/textures/moves.png");
	check_img_texture(p);
	p->img[0] = mlx_texture_to_image(p->mlx, p->texture[0]);
	p->img[1] = mlx_texture_to_image(p->mlx, p->texture[1]);
	p->img[2] = mlx_texture_to_image(p->mlx, p->texture[2]);
	p->img[3] = mlx_texture_to_image(p->mlx, p->texture[3]);
	p->img[4] = mlx_texture_to_image(p->mlx, p->texture[4]);
	p->img[5] = mlx_texture_to_image(p->mlx, p->texture[5]);
	p->img[6] = mlx_texture_to_image(p->mlx, p->texture[6]);
	p->img[7] = mlx_texture_to_image(p->mlx, p->texture[7]);
}
