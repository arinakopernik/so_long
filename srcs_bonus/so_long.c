/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:12:11 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/25 13:15:15 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_map *map)
{
	mlx_hook(map->win, 2, 0, key_hook, map);
	mlx_hook(map->win, 17, 0, game_over, map);
	mlx_loop_hook(map->mlx, draw_map, map);
	mlx_loop(map->mlx);
}

t_map	*parser(int argc, char **argv)
{
	t_map	*map;
	char	*line;

	argum_check(argc, argv);
	line = get_line(argv);
	map = map_init(line);
	init_pics(map);
	check_map(map, argv);
	check_line_map(map);
	check_border(map, -1);
	check_args_map(map);
	return (map);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = parser(argc, argv);
	start_game(map);
	free_map(map);
	return (0);
}

void	argum_check(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Wrong number of arguments");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		ft_error("Map is not .ber");
}
