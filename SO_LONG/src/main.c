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
	char *final;

	if(argc != 2)
		ft_error();
	final = ft_strdup (argv[1] + ft_strlen(argv[1]) - 4);
	if(ft_strncmp(final, ".ber", 4))
		ft_error();
	read_map(&game, argv[1]);

}
// con get_next_line leeremos linea a linea el archivo y juntamos en un string con strjoin
// luego dividimos el string en un array de strings con ft_split
void read_map(t_game *game, char *str)
{
	int fd;
	char *line;
	char *linetotal;
	char *temp;

	linetotal = NULL;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while(line != NULL)
	{
		temp = linetotal;
		linetotal = ft_strjoin(linetotal, line);
		if(line == NULL)
		{
			free(temp);
			free(line);
			ft_error();
			return;
		}
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	process_map_line(game, linetotal);
	parsing(game, str);
	free(linetotal);
}

void process_map_line(t_game *game, char *line)
{
	char **map;
	int i;

	i  = 0;
	game->map = malloc(sizeof(char*) * (game->rows + 1));
	if (game->map == NULL)
		ft_error();
	map = ft_split(line, '\n');
	while(map[i] != NULL)
	{
		game->map[i] = ft_strdup(map[i]);
		if(game->map[i] == NULL)
			ft_error();
		i++;
	}
	game->map[i] = NULL;
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}


//* * Esta función se asegura de que el programa se ejecute con el número correcto de argumentos
/* y que el argumento adicional sea un archivo con la extensión .ber. */
/*char **check_params(int argc, char **argv, t_game *game)
{
	int fl;

	if (argv != 2)
		ft_error();
	fl = ft_strlen(argv[1]);
	if(ft_strrncmp(argv[1] + (fl - 4), ".ber", 4) == NULL)
		ft_error();
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
} */ 