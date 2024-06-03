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
	if(ft_strncmp(final, ".ber", 4) == 0)
		ft_error();
	read_map(&game, argv[1]);

}

void read_map(t_game *game, char *str)
{
	int fd;
	char *line;

	fd = open(str, O_RDONLY);
	// norminette
	while ((line = get_next_line(fd)) > 0)
	{
		process_map_line(game, line);
		free(line);
	}
	check_rect_map(game);
	check_components(game);
}

void process_map_line(t_game *game, char *line)
{
	int row;
	int len;

	row = game->rows;
	len = ft_strlen(line);
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