/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:13:41 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/16 14:52:24 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_findend(char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
	{
		if (str[a] == '\n')
			return ((char *)str + a);
		a++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*ft_strjoin_gnl(char *remain, char *buffer)
{
	int		a;
	int		b;
	char	*str;

	if (!remain)
	{
		remain = malloc(sizeof(char) * 1);
		remain[0] = '\0';
	}
	if (!remain || ! buffer)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(remain) + ft_strlen(buffer) + 1));
	if (str == 0)
		return (NULL);
	a = -1;
	b = 0;
	if (remain)
		while (remain[++a] != '\0')
			str[a] = remain[a];
	while (buffer[b])
		str[a++] = buffer[b++];
	str[a] = '\0';
	free(remain);
	return (str);
}
