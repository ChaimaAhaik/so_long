/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:34:52 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/30 13:13:44 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strjoin(char *sttc, char *buff)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	int		len;

	i = 0;
	j = 0;
	if (!sttc && !buff)
		return (NULL);
	len = ft_strlen(sttc) + ft_strlen(buff);
	if (len == 0)
		return (free(sttc), NULL);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (sttc && sttc[i])
	{
		ptr[i] = sttc[i];
		i++;
	}
	while (buff && buff[j])
		ptr[i++] = buff[j++];
	return (ptr[i] = '\0', free(sttc), sttc = NULL, ptr);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if ((char)c == '\0')
		return ((char *)str + ft_strlen(str));
	while (*str != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strdup(char *str)
{
	size_t	i;
	size_t	size;
	char	*ptr;

	i = 0;
	size = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		size++;
		i++;
	}
	ptr = (char *)malloc(1 * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static size_t	ft_countchar(int nb)
{
	size_t	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	len;
	long	num;

	num = n;
	if (n <= 0)
		num *= -1;
	len = ft_countchar(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n == 0)
		ptr[0] = '0';
	while (--len >= 0 && num != 0)
	{
		ptr[len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		ptr[len] = '-';
	return (ptr);
}
