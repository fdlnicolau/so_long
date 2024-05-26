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

typedef struct s_game
{
    char **map;
    int rows;
    int cols;
    int players;
    int exit;
    int collectibles;

} t_game;

void    init_game(t_game *game);
void    read_map(int fd, t_game *game);
int     map_size(int fd);
int     check_line(char *line, int cols);
char    **check_params(int argc, char **argv, t_game *game);
int     main(int argc, char **argv);

#endif