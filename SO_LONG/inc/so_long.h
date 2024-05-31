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

# include <libft.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "/sgoinfre/shared/MLX42/build/libmlx42.a"

typedef struct s_game
{
    char **map;
    int rows;
    int cols;
    int players;
    int exit;
    int collectibles;
    int map_height; // Nueva variable para almacenar la altura del mapa
    void *map_to_free; 

} t_game;

void free_map(t_game *game);
void check_walls(t_game game);
void ft_error();
void check_components(t_game *game);
void check_rect_map(t_game *game);
int first_index_valid(char *str);
int count_comp(char **map, char c);
void    init_game(t_game *game);
void    read_map(t_game *game, char *str);
int     map_size(int fd);
int     check_line(char *line, int cols);
char    **check_params(int argc, char **argv, t_game *game);
int     main(int argc, char **argv);

#endif