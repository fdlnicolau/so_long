/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:12:42 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/25 17:12:42 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define S 64
#define EXTENSION_NO_BER -1
#define MAP_ERROR -3


#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

typedef struct s_game
{
	char **map;
	int rows;
	int cols;
	int players;
	int exit;
	int collectibles;
	int hgt;
	int wth; 
	void *map_to_free; 
	void *window;
	int player_x;
	int player_y;
	mlx_texture_t *floor_tex;
	mlx_texture_t *wall_tex;
	mlx_texture_t *collectible_tex;
	mlx_texture_t *player_tex;
	mlx_texture_t *exit_tex;
	mlx_texture_t *collect_text;
	mlx_image_t *floor_img;
	mlx_image_t *exit_img;
	mlx_image_t *player_img;
	mlx_image_t *wall_img;
	mlx_image_t *collect_img;
	int floor_height;
	int floor_width;
	int exit_height;
	int exit_width;
	int player_height;
	int player_width;
	int *player_ps;
	int player_exit;
	int wall_height;
	int wall_width;
	int collect_height;
	int collect_width;
	mlx_t *mlx;
	mlx_texture_t *collect_tex;
	int steps;
	mlx_image_t *str;
	char *temp;
} t_game;

void render_game_state(t_game *game);
void game_loop(t_game *game);
void	move_player(t_game *game, int direction);
void	init_key_hook(mlx_key_data_t keydata, void *game);
int free_map(t_game *game);
void game_init(t_game *game);
void texture_to_img(t_game *game);
void load_png(t_game *game);
void img_to_window(t_game *game);
mlx_image_t *convert_texture_to_image(void *mlx, mlx_texture_t *texture);
void load_player(t_game *game);
void load_image(t_game *game);
void game_control(t_game *game);
void    ft_error(const char *str);
void free_game(t_game *game) ;
t_game *game_memory_init(t_game **game);
void check_components(t_game *game);
void preparation_map(t_game *game);
void check_map_content(t_game *game, char cell, int i, int j);
void copy_line(t_game *game, char *line, int i);
void check_status(t_game *game);
//CHECK_MAP
void check_map(char *str, t_game *game);
void read_map(t_game *game, char *str);
char *reading(int fd, t_game *game);

//void free_map(t_game *game);
void check_walls(t_game *game);
void check_components(t_game *game);
void check_components(t_game *game);
void check_rect_map(t_game *game);
int **init_visit(int hgt, int wth);
int count_comp(char **map, char c);
int count_comp(char **map, char c);
int parsing(t_game *game, char *argv);
//void    init_game(t_game *game);
int	**start_check_path(t_game *game, int i, int j);
void    read_map(t_game *game, char *str);
void check_path(t_game *game, int i, int j, int **visit);
int     map_size(int fd);
//int     check_line(char *line, int cols);
void check_collectibles(t_game *game, int **visit);
//char    **check_params(int argc, char **argv, t_game *game);
void process_map_line(t_game *game, char *line);

#endif