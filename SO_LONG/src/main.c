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
	t_game game;

    init_game(&game);
    if(argc == 1)
        error(&game, "Missing map (./so_long maps/intra.ber)");
    if(argc > 2)
        error(&game, "Too many arguments");
    parsing(&game, argv[1]);
    // Aquí puedes continuar con la lógica de tu juego usando `map` y `game`
	return (0);
}

/* Esta función se asegura de que el programa se ejecute con el número correcto de argumentos
y que el argumento adicional sea un archivo con la extensión .ber. */
char **check_params(int argc, char **argv, t_game *game)
{
    int fl;

    if (argc != 2)
    {
        ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
        exit(1);
    }
    fl = ft_strlen(argv[1]);
    if(ft_strrncmp(argv[1] + [fl - 4], ".ber", 4) == NULL)
    {
        ft_putstr_fd("Error\nInvalid file extension, use .ber!\n", 2);
		close(fd);
        exit(1);
    }
}

void init_map(char **argv, t_game *game)
{
    char *line;
    int  i;

    line = get_next_line(game->fd);
    is_emtpy(line);
    i = 0;
    while(line && !line[0] == '\n')
    {
        if(i >= MAP_HEIGHT / IMG_HEIGHT)
        {
            ft_putstr_fd("Error\nInvalid map\n", 2);
            exit(1);
        }
        if(gsmr->map.repo == NULL)
        {
            game->map.repo = ft_strdup(line);
        }
        else
        {
            game->map.repo = gnl_strjoin(game->map.repo, line);
        }
    }
}

void read_map(int fd, t_game *game)
{
	char *line;
	int fd;
	int ret;
    int file;

    file = 0;
    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        ft_putstr_fd("Error\nInvalid file\n", 2);
        exit(1);
    }
    ret = get_next_line(fd);
    
    while(line[first_index_valid(line)] == '1' || line[first_index_valid(line)] == '0')
    {
        game->cols = ft_strlen(line);
        game->rows++;
        free(line);
        ret = get_next_line(fd);
    }
	while((line = get_next_line(fd)) != NULL)
	{
		if(cols == 0)
		{
			cols = ft_strlen(line);
		}
		else if((int)ft_strlen(line) != game->cols)
		{
			ft_putstr_fd("Error\nInvalid map\n", 2);
			exit(1);
		}
		if(!check_line(line, game->cols))
		{
			ft_putstr_fd("Error\nInvalid map\n", 2);
			exit(1);
		}
		rows++;
		free(line);
	}
	if(cols == 0 || rows == 0)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(1);
	}
	close(fd);
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