/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:19:06 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/18 14:45:57 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	argum_check(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Wrong number of argc");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		ft_error("Map is not .ber");
}

char	*get_line(char **argv)
{
	int		fd;
	char	*line;
	char	*subline;
	char	*temp;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Could not open map");
	line = ft_strdup("");
	while (1)
	{
		subline = get_next_line(fd);
		if (!subline)
			break ;
		temp = line;
		line = ft_strjoin(line, subline);
		free(temp);
		free(subline);
	}
	close(fd);
	return (line);
}

t_map	*map_init(char *line)
{
	t_map	*map;
	int		i;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = ft_split(line, '\n');
	while (map->map[i])
		i++;
	map->width = i;
	map->length = ft_strlen(map->map[0]);
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->length * SIZE_X,
			map->width * SIZE_Y, "so_long");
	map->collect = 0;
	map->steps = 0;
	free(line);
	return (map);
}

void	init_pics(t_map *map)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	map->img.wall = mlx_xpm_file_to_image(map->mlx, WALL, &x, &y);
	map->img.ground = mlx_xpm_file_to_image(map->mlx, GROUND, &x, &y);
	map->img.collect = mlx_xpm_file_to_image(map->mlx, COLLECT, &x, &y);
	map->img.exit = mlx_xpm_file_to_image(map->mlx, EXIT, &x, &y);
	map->img.exit_open = mlx_xpm_file_to_image(map->mlx, EXIT_OPEN, &x, &y);
	map->img.player = mlx_xpm_file_to_image(map->mlx, PLAYER, &x, &y);
	map->img.player1 = mlx_xpm_file_to_image(map->mlx, PLAYER1, &x, &y);
	map->img.player2 = mlx_xpm_file_to_image(map->mlx, PLAYER2, &x, &y);
	map->img.player3 = mlx_xpm_file_to_image(map->mlx, PLAYER3, &x, &y);
	map->img.player_now = map->img.player;
	if (!map->img.wall || !map->img.ground || !map->img.collect
		|| !map->img.exit || !map->img.player)
		ft_error("Could not make img");
}

void	check_exit(t_map *map)
{
	int	exit;
	int	i;
	int	j;

	exit = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (map->map[i][j] == 'E')
				exit++;
		}
	}
	if (exit < 1)
		ft_error("No exit");
}
