/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:46:06 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/24 14:22:42 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation(t_map *map)
{
	if (map->img.collect == map->img.collect1)
		map->img.collect = map->img.collect2;
	else if (map->img.collect == map->img.collect2)
		map->img.collect = map->img.collect1;
	if (map->img.bee == map->img.bee1)
		map->img.bee = map->img.bee2;
	else if (map->img.bee == map->img.bee2)
		map->img.bee = map->img.bee1;
}

void	enemy_init(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'H')
	{
		map->h_enemy_coord.x = j;
		map->h_enemy_coord.y = i;
		count_horizon(map);
	}
	else if (map->map[i][j] == 'V')
	{
		map->v_enemy_coord.x = j;
		map->v_enemy_coord.y = i;
		count_vertical(map);
	}
}

void	count_vertical(t_map *map)
{
	int	temp;

	temp = map->v_enemy_coord.y;
	while (map->map[map->v_enemy_coord.y - 1][map->v_enemy_coord.x] == '0')
	{
		map->num_up++;
		map->flag_up = 1;
		map->v_enemy_coord.y--;
	}
	map->v_enemy_coord.y = temp;
	while (map->map[map->v_enemy_coord.y + 1][map->v_enemy_coord.x] == '0')
	{
		map->num_down++;
		map->flag_down = 1;
		map->v_enemy_coord.y++;
	}
	map->v_enemy_coord.y = temp;
}

void	count_horizon(t_map *map)
{
	int	temp;

	temp = map->h_enemy_coord.x;
	while (map->map[map->h_enemy_coord.y][map->h_enemy_coord.x - 1] == '0')
	{
		map->num_left++;
		map->flag_left = 1;
		map->h_enemy_coord.x--;
	}
	map->h_enemy_coord.x = temp;
	while (map->map[map->h_enemy_coord.y][map->h_enemy_coord.x + 1] == '0')
	{
		map->num_right++;
		map->flag_right = 1;
		map->h_enemy_coord.x++;
	}
	map->h_enemy_coord.x = temp;
}
