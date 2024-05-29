/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:40:29 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/20 15:40:29 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int main(int argc, char **argv)
{
	t_game *game;
	int fd;

	game = NULL;
	ckeck_params(argc, argv, &game);
	fd = open(argv[1], O_RDONLY);
    init_game(&game);
	if (fd == -1)
		error();
	game = malloc(sizeof(t_game));
	if(!game)
		error();
	read_map(game);
		return (0);
}

/* Esta función se asegura de que el programa se ejecute con el número correcto de argumentos
y que el argumento adicional sea un archivo con la extensión .ber. */
char **check_params(int argc, char **argv, t_game *game)
{
	int fl;

	if (argv != 2)
		ft_error();
	fl = ft_strlen(argv[1]);
	if(ft_strrncmp(argv[1] + (fl - 4), ".ber", 4) == NULL)
		ft_error();
}

void read_map(t_game *game)
{
	check_rect_map(game);
	check_components(game);
	check_walls(game);
}

int map_size(int fd)
{
    char *line;
    int size;

    size = 0;
    while((line = get_next_line(fd)) != NULL)
    {
        size++;
        free(line);
    }
    return (size);
}

int check_line(char *line, int cols)
{
    int i;

    i = 0;
    while(line[i] != '\0')
    {
        if(line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'E' && line[i] != 'C')
        {
            ft_putstr_fd("Error\nInvalid character in map\n", 2);
            return(0);
        }
        i++;
    }
    return (i == cols);
}

void init_game(t_game *game)
{
    game->map = NULL;
    game->rows = 0;
    game->cols = 0;
    game->players = 0;
    game->exit = 0;
    game->collectibles = 0;
}