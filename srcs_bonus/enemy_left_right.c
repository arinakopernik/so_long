/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_left_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:00:22 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/24 16:29:26 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move_left_right(t_map *map)
{
	if (map->flag_left != 0)
	{
		enemy_go_left(map);
		mlx_put_image_to_window(map->mlx, map->win, map->img.bee,
			map->h_enemy_coord.x * SIZE_X, map->h_enemy_coord.y * SIZE_Y);
		if (map->num_left == 0)
		{
			map->flag_left = 0;
			map->flag_right = 1;
		}
	}
	else if (map->flag_right != 0)
	{
		enemy_go_right(map);
		mlx_put_image_to_window(map->mlx, map->win, map->img.bee,
			map->h_enemy_coord.x * SIZE_X, map->h_enemy_coord.y * SIZE_Y);
		if (map->num_right == 0)
		{
			map->flag_right = 0;
			map->flag_left = 1;
		}
	}
}

void	enemy_go_left(t_map *map)
{
	if (map->map[map->h_enemy_coord.y][map->h_enemy_coord.x - 1] == 'P')
		game_over(map);
	map->map[map->h_enemy_coord.y][map->h_enemy_coord.x - 1] = 'V';
	map->map[map->h_enemy_coord.y][map->h_enemy_coord.x] = '0';
	map->h_enemy_coord.x--;
	map->num_left--;
	map->num_right++;
}

void	enemy_go_right(t_map *map)
{
	if (map->map[map->h_enemy_coord.y][map->h_enemy_coord.x + 1] == 'P')
		game_over(map);
	map->map[map->h_enemy_coord.y][map->h_enemy_coord.x + 1] = 'V';
	map->map[map->h_enemy_coord.y][map->h_enemy_coord.x] = '0';
	map->h_enemy_coord.x++;
	map->num_left++;
	map->num_right--;
}
