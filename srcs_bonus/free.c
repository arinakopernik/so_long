/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:59:10 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/25 13:54:03 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img.wall);
	mlx_destroy_image(map->mlx, map->img.ground);
	mlx_destroy_image(map->mlx, map->img.player1);
	mlx_destroy_image(map->mlx, map->img.player2);
	mlx_destroy_image(map->mlx, map->img.player3);
	mlx_destroy_image(map->mlx, map->img.player);
	mlx_destroy_image(map->mlx, map->img.collect1);
	mlx_destroy_image(map->mlx, map->img.collect2);
	mlx_destroy_image(map->mlx, map->img.exit);
	mlx_destroy_image(map->mlx, map->img.exit_open);
	mlx_destroy_image(map->mlx, map->img.bee1);
	mlx_destroy_image(map->mlx, map->img.bee2);
}

void	free_map(t_map *map)
{
	int	a;

	a = -1;
	mlx_destroy_window(map->mlx, map->win);
	destroy_img(map);
	while (map->map[++a])
		free(map->map[a]);
	free(map->map);
	free(map);
}
