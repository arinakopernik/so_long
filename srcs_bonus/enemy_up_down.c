/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_up_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:10:25 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/24 16:29:18 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move_up_down(t_map *map)
{
	if (map->flag_up != 0)
	{
		enemy_go_up(map);
		mlx_put_image_to_window(map->mlx, map->win, map->img.bee,
			map->v_enemy_coord.x * SIZE_X, map->v_enemy_coord.y * SIZE_Y);
		if (map->num_up == 0)
		{
			map->flag_up = 0;
			map->flag_down = 1;
		}
	}
	else if (map->flag_down != 0)
	{
		enemy_go_down(map);
		mlx_put_image_to_window(map->mlx, map->win, map->img.bee,
			map->v_enemy_coord.x * SIZE_X, map->v_enemy_coord.y * SIZE_Y);
		if (map->num_down == 0)
		{
			map->flag_down = 0;
			map->flag_up = 1;
		}
	}
}

void	enemy_go_up(t_map *map)
{
	if (map->map[map->v_enemy_coord.y - 1][map->v_enemy_coord.x] == 'P')
		game_over(map);
	map->map[map->v_enemy_coord.y - 1][map->v_enemy_coord.x] = 'V';
	map->map[map->v_enemy_coord.y][map->v_enemy_coord.x] = '0';
	map->v_enemy_coord.y--;
	map->num_up--;
	map->num_down++;
}

void	enemy_go_down(t_map *map)
{
	if (map->map[map->v_enemy_coord.y + 1][map->v_enemy_coord.x] == 'P')
		game_over(map);
	map->map[map->v_enemy_coord.y + 1][map->v_enemy_coord.x] = 'V';
	map->map[map->v_enemy_coord.y][map->v_enemy_coord.x] = '0';
	map->v_enemy_coord.y++;
	map->num_up++;
	map->num_down--;
}
