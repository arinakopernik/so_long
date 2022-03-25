/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:29:44 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/24 16:29:08 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_up(t_map *map)
{
	enemy_check(map, 1);
	if (map->map[map->player_coord.y - 1][map->player_coord.x] == '0')
	{
		go_up(map);
		map->img.player_now = map->img.player3;
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			map->player_coord.x * SIZE_X, map->player_coord.y * SIZE_Y);
	}
	else if (map->map[map->player_coord.y - 1][map->player_coord.x] == '1')
	{
		map->img.player_now = map->img.player3;
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			map->player_coord.x * SIZE_X, map->player_coord.y * SIZE_Y);
	}
	else if (map->map[map->player_coord.y - 1][map->player_coord.x] == 'C')
	{
		go_up(map);
		map->collect--;
		map->img.player_now = map->img.player3;
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			map->player_coord.x * SIZE_X, map->player_coord.y * SIZE_Y);
	}
	else if (map->map[map->player_coord.y - 1][map->player_coord.x] == 'E'
		&& map->collect == 0)
		game_over(map);
}

void	move_player_down(t_map *map)
{
	enemy_check(map, 2);
	if (map->map[map->player_coord.y + 1][map->player_coord.x] == '0')
	{
		go_down(map);
		map->img.player_now = map->img.player;
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			map->player_coord.x * SIZE_X, map->player_coord.y * SIZE_Y);
	}
	else if (map->map[map->player_coord.y + 1][map->player_coord.x] == '1')
	{
		map->img.player_now = map->img.player;
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			map->player_coord.x * SIZE_X, map->player_coord.y * SIZE_Y);
	}
	else if (map->map[map->player_coord.y + 1][map->player_coord.x] == 'C')
	{
		go_down(map);
		map->collect--;
		map->img.player_now = map->img.player;
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			map->player_coord.x * SIZE_X, map->player_coord.y * SIZE_Y);
	}
	else if (map->map[map->player_coord.y + 1][map->player_coord.x] == 'E'
		&& map->collect == 0)
		game_over(map);
}

void	move_player_left(t_map *map)
{
	enemy_check(map, 3);
	if (map->map[map->player_coord.y][map->player_coord.x - 1] == '0')
	{
		go_left(map);
		map->img.player_now = map->img.player2;
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			map->player_coord.x * SIZE_X, map->player_coord.y * SIZE_Y);
	}
	else if (map->map[map->player_coord.y][map->player_coord.x - 1] == '1')
	{
		map->img.player_now = map->img.player2;
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			map->player_coord.x * SIZE_X, map->player_coord.y * SIZE_Y);
	}
	else if (map->map[map->player_coord.y][map->player_coord.x - 1] == 'C')
	{
		go_left(map);
		map->collect--;
		map->img.player_now = map->img.player2;
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			map->player_coord.x * SIZE_X, map->player_coord.y * SIZE_Y);
	}
	else if (map->map[map->player_coord.y][map->player_coord.x - 1] == 'E'
		&& map->collect == 0)
		game_over(map);
}

void	move_player_right(t_map *map)
{
	enemy_check(map, 4);
	if (map->map[map->player_coord.y][map->player_coord.x + 1] == '0')
	{
		go_right(map);
		map->img.player_now = map->img.player1;
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			map->player_coord.x * SIZE_X, map->player_coord.y * SIZE_Y);
	}
	else if (map->map[map->player_coord.y][map->player_coord.x + 1] == '1')
	{
		map->img.player_now = map->img.player1;
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			map->player_coord.x * SIZE_X, map->player_coord.y * SIZE_Y);
	}
	else if (map->map[map->player_coord.y][map->player_coord.x + 1] == 'C')
	{
		go_right(map);
		map->collect--;
		map->img.player_now = map->img.player1;
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			map->player_coord.x * SIZE_X, map->player_coord.y * SIZE_Y);
	}
	else if (map->map[map->player_coord.y][map->player_coord.x + 1] == 'E'
		&& map->collect == 0)
		game_over(map);
}

void	enemy_check(t_map *map, int f)
{
	if (f == 1)
	{
		if (map->map[map->player_coord.y - 1][map->player_coord.x] == 'H' ||
			map->map[map->player_coord.y - 1][map->player_coord.x] == 'V')
			game_over(map);
	}
	if (f == 2)
	{
		if (map->map[map->player_coord.y + 1][map->player_coord.x] == 'H' ||
			map->map[map->player_coord.y + 1][map->player_coord.x] == 'V')
			game_over(map);
	}
	if (f == 3)
	{
		if (map->map[map->player_coord.y][map->player_coord.x - 1] == 'H' ||
			map->map[map->player_coord.y][map->player_coord.x - 1] == 'V')
			game_over(map);
	}
	if (f == 4)
	{
		if (map->map[map->player_coord.y][map->player_coord.x + 1] == 'H' ||
			map->map[map->player_coord.y][map->player_coord.x + 1] == 'V')
			game_over(map);
	}
}
