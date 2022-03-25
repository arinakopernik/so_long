/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:23:33 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/25 13:49:44 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_map *map)
{
	draw_map(map);
	if (keycode == UP)
		move_player_up(map);
	if (keycode == DOWN)
		move_player_down(map);
	if (keycode == LEFT)
		move_player_left(map);
	if (keycode == RIGHT)
		move_player_right(map);
	if (keycode == ESC)
		game_over(map);
	enemy_move_up_down(map);
	enemy_move_left_right(map);
	return (0);
}

int	draw_map(t_map *map)
{
	int			i;
	int			j;
	static int	anim;
	char		*counter;

	anim++;
	if (anim > 8)
	{
		animation(map);
		anim = 0;
	}
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
			put_map(map, i, j);
	}
	counter = ft_itoa(map->steps);
	mlx_string_put(map->mlx, map->win, 10, 10, 10, "Steps made:");
	mlx_string_put(map->mlx, map->win, 120, 10, 10, counter);
	free(counter);
	return (0);
}

void	put_map(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->img.wall,
			j * SIZE_X, i * SIZE_Y);
	if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img.ground,
			j * SIZE_X, i * SIZE_Y);
	if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->img.collect,
			j * SIZE_X, i * SIZE_Y);
	if (map->map[i][j] == 'H' || map->map[i][j] == 'V')
		mlx_put_image_to_window(map->mlx, map->win, map->img.bee,
			j * SIZE_X, i * SIZE_Y);
	if (map->map[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->img.player_now,
			j * SIZE_X, i * SIZE_Y);
	put_exit(map, i, j);
}

void	put_exit(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'E' && map->collect != 0)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img.ground,
			j * SIZE_X, i * SIZE_Y);
		mlx_put_image_to_window(map->mlx, map->win, map->img.exit,
			j * SIZE_X, i * SIZE_Y);
	}
	if (map->map[i][j] == 'E' && map->collect == 0)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img.ground,
			j * SIZE_X, i * SIZE_Y);
		mlx_put_image_to_window(map->mlx, map->win, map->img.exit_open,
			j * SIZE_X, i * SIZE_Y);
	}
}

int	game_over(t_map *map)
{
	ft_printf("Game over\n");
	free_map(map);
	exit(0);
}
