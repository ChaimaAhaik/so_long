/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:29:02 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/04 10:43:46 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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


