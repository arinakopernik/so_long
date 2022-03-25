/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:23:40 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/25 13:14:46 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_map *map, char **argv)
{
	int		fd;
	int		a;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Could not open for check");
	a = 0;
	while (1)
	{
		line = get_next_line(fd);
		a++;
		if (!line)
			break ;
		free(line);
	}
	if (a != map->width + 1)
		ft_error("Wrong width");
	close(fd);
}

void	check_line_map(t_map *map)
{
	int		x;
	int		y;
	char	*str;

	str = "01PCEHV";
	x = -1;
	while (map->map[++x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (!ft_strrchr(str, map->map[x][y]))
				ft_error("Wrong character");
			y++;
		}
		if (map->length != y)
			ft_error("Wrong length");
	}
}

void	check_border(t_map *map, int i)
{
	int	j;

	while (map->map[0][++i])
	{
		if (map->map[0][i] != '1')
			ft_error("Upper border is wrong");
	}
	i = -1;
	while (map->map[map->width - 1][++i])
	{
		if (map->map[map->width - 1][i] != '1')
			ft_error("Bottom border is wrong");
	}
	i = 0;
	while (map->map[++i] && i < map->width - 1)
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][0] != '1')
				ft_error("Left border is wrong");
			if (map->map[i][map->length - 1] != '1')
				ft_error("Right border is wrong");
		}
	}
}

void	check_args_map(t_map *map)
{
	int	player;
	int	i;
	int	j;

	player = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'P')
				player_init(map, i, j, &player);
			if (map->map[i][j] == 'H' || map->map[i][j] == 'V')
				enemy_init(map, i, j);
			else if (map->map[i][j] == 'C')
				map->collect++;
		}
	}
	if (player != 1)
		ft_error("No player");
	if (map->collect < 0)
		ft_error("No collectible");
	check_exit(map);
}

void	player_init(t_map *map, int i, int j, int *player)
{
	map->player_coord.x = j;
	map->player_coord.y = i;
	*player += 1;
}
