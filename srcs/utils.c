/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:29:25 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/25 13:43:49 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_printf("Error: %s\n", str);
	exit(0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*p;

	if (!s1)
		return (0);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	p = (char *)malloc((a + b + 1) * sizeof(char));
	if (p == 0)
		return (0);
	a = 0;
	b = 0;
	while (s1[a])
	{
		p[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		p[a + b] = s2[b];
		b++;
	}
	p[a + b] = '\0';
	return (p);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n && s1[a] && s2[a])
	{
		if (s1[a] != s2[a])
			return (((unsigned char *)s1)[a] - ((unsigned char *)s2)[a]);
		a++;
	}
	if (a < n)
		return (((unsigned char *)s1)[a] - ((unsigned char *)s2)[a]);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	a;

	a = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + a));
	while (a != 0)
	{
		if (s[a - 1] == (char)c)
			return ((char *)(s + a - 1));
		a--;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		a;
	int		b;

	a = ft_strlen(s1);
	b = 0;
	p = malloc((a + 1) * sizeof(char));
	if (!p)
		return (0);
	while (s1[b])
	{
		p[b] = s1[b];
		b++;
	}
	p[b] = '\0';
	return (p);
}
