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
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

} t_game;

//void free_map(t_game *game);
void check_walls(t_game *game);
void ft_error();
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