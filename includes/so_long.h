/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrianna <lbrianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:00:39 by lbrianna          #+#    #+#             */
/*   Updated: 2022/03/25 13:53:54 by lbrianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../ft_printf/ft_printf.h"

# define WALL		"textures/wall.xpm"
# define GROUND		"textures/ground.xpm"
# define COLLECT	"textures/diamond.xpm"
# define COLLECT1	"textures/collect1.xpm"
# define COLLECT2	"textures/collect2.xpm"
# define EXIT		"textures/exit.xpm"
# define EXIT_OPEN	"textures/exit_open.xpm"
# define PLAYER		"textures/player.xpm"
# define PLAYER1	"textures/player_right.xpm"
# define PLAYER2	"textures/player_left.xpm"
# define PLAYER3	"textures/player_back.xpm"
# define BEE1		"textures/bee1.xpm"
# define BEE2		"textures/bee2.xpm"

# define SIZE_X 64
# define SIZE_Y 64

# define ESC 	53
# define UP		13
# define DOWN 	1
# define RIGHT	2
# define LEFT 	0

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_img
{
	void	*wall;
	void	*ground;
	void	*player;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*collect;
	void	*collect1;
	void	*collect2;
	void	*exit;
	void	*exit_open;
	void	*bee;
	void	*bee1;
	void	*bee2;
	void	*player_now;
}	t_img;

typedef struct s_map
{
	int		length;
	int		width;
	int		steps;
	int		enemy;
	int		collect;
	void	*mlx;
	void	*win;
	char	**map;
	int		flag_up;
	int		num_up;
	int		flag_down;
	int		num_down;
	int		flag_left;
	int		num_left;
	int		flag_right;
	int		num_right;
	t_img	img;
	t_coord	player_coord;
	t_coord	h_enemy_coord;
	t_coord	v_enemy_coord;
}		t_map;

int		main(int argc, char **argv);
t_map	*parser(int argc, char **argv);

void	argum_check(int argc, char **argv);
char	*get_line(char **argv);
t_map	*map_init(char *line);
void	init_pics(t_map *map);
void	check_map(t_map *map, char **argv);
void	check_line_map(t_map *map);
void	check_border(t_map *map, int i);
void	check_args_map(t_map *map);
void	player_init(t_map *map, int i, int j, int *player);
void	check_exit(t_map *map);

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
void	ft_error(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

char	*get_next_line(int fd);
char	*ft_findend(char *str);
int		ft_strlen(const char *str);
char	*ft_strjoin_gnl(char *remain, char *buffer);

void	start_game(t_map *map);
int		key_hook(int keycode, t_map *map);
int		game_over(t_map *map);
int		draw_map(t_map *map);
void	put_map(t_map *map, int i, int j);
void	put_exit(t_map *map, int i, int j);

void	move_player_up(t_map *map);
void	go_up(t_map *map);
void	move_player_down(t_map *map);
void	go_down(t_map *map);
void	move_player_left(t_map *map);
void	go_left(t_map *map);
void	move_player_right(t_map *map);
void	go_right(t_map *map);

void	flags_init(t_map *map);
void	animation(t_map *map);
void	enemy_init(t_map *map, int i, int j);
void	enemy_check(t_map *map, int f);
void	count_vertical(t_map *map);
void	count_horizon(t_map *map);
void	enemy_move_up_down(t_map *map);
char	*ft_itoa(int n);
void	enemy_go_up(t_map *map);
void	enemy_go_down(t_map *map);
void	enemy_move_left_right(t_map *map);
void	enemy_go_left(t_map *map);
void	enemy_go_right(t_map *map);

void	destroy_img(t_map *map);
void	free_map(t_map *map);
#endif