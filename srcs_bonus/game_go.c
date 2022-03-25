/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_go.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:30:40 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/18 17:06:30 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_right(t_map *map)
{
	map->map[map->player_coord.y][map->player_coord.x + 1] = 'P';
	map->map[map->player_coord.y][map->player_coord.x] = '0';
	map->player_coord.x++;
	map->steps++;
}

void	go_left(t_map *map)
{
	map->map[map->player_coord.y][map->player_coord.x - 1] = 'P';
	map->map[map->player_coord.y][map->player_coord.x] = '0';
	map->player_coord.x--;
	map->steps++;
}

void	go_down(t_map *map)
{
	map->map[map->player_coord.y + 1][map->player_coord.x] = 'P';
	map->map[map->player_coord.y][map->player_coord.x] = '0';
	map->player_coord.y++;
	map->steps++;
}

void	go_up(t_map *map)
{
	map->map[map->player_coord.y - 1][map->player_coord.x] = 'P';
	map->map[map->player_coord.y][map->player_coord.x] = '0';
	map->player_coord.y--;
	map->steps++;
}
