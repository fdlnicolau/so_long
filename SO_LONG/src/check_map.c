/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:04:14 by lnicolau          #+#    #+#             */
/*   Updated: 2024/06/07 16:14:40 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void read_map(t_game *game, char *str)
{
	int fd;
	char * lines;

	fd = open(str, O_RDONLY);
	lines = reading(fd);
	close(fd);
	preparation_map(game, lines);
	//parsing(game, str);
	free(lines);
}
char *reading(int fd)
{
	char *line;
	char *tmp;
	char *linetotal;

	allocate_grid_memory(game);
	fd = open_file(argv);
	line = get_next_line(fd);
	while (line)
	{
		copy_line(game, line, i);
		j = 0;
		while (j < game->map.width)
		{
			check_map_content(game, game->map.grid[i][j], i, j);
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map.grid[i] = NULL;
	write(1,"pepa", 4);
	return(linetotal);
}

void preparation_map(t_game *game, char *line)
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
//Comprueba si el mapa es rectangular
void check_rect_map(t_game *game)
{
	int i;
	int j;
	int len;

	i = 0;
	len = ft_strlen(game->map[0]);
	if(ft_strlen(game->map[i]) <= 1)
		ft_error();
	if(ft_strlen(game->map[0]) < 3)
		ft_error();
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
			j++;
		if (j != len)
			ft_error();
		i++;
	}
	if(i == 0)
		ft_error();
	if(i < 3)
		ft_error();
	game->wth = len;
	game->hgt = i;
}

//Comprueba si el mapa contiene los componentes necesarios
void check_components(t_game *game)
{
	int i;
	int j;


	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (ft_strchr("10CEP", game->map[i][j]) == NULL)
				ft_error();
			j++;
		}
		i++;
	}
	if (count_comp(game->map, 'P') != 1)
		ft_error();
	if(count_comp(game->map, 'E') != 1)
		ft_error();
	if(count_comp(game->map, 'C') == 0)
		ft_error();
}

void ft_error()//hay que arreglarlo
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void check_walls(t_game *game)
{
	int	i;
	size_t	j;

	j = 0;
	i = 0;

	while ( j < ft_strlen(game->map[0]))
	{
		if (game->map[0][j] != '1' || game->map[game->hgt - 1][j] != '1')
			ft_error();
		j++;
	}

	while( i < game->hgt)
	{
		if (game->map[i][0] != '1' || game->map[i][game->wth - 1] != '1')
			ft_error();
		i++;
	}
}

int **start_check_path(t_game *game, int i, int j)
{
	int **visit;
	visit = init_visit(game->hgt, game->wth);

	while(i < game->hgt)
	{
		j = 0;
		while(j < game->wth)
		{
			if (game->map[i][j] == 'P')
				check_path(game, i, j, visit);
			j++;
		}
		i++;
	}
	if (!game->exit)
		ft_error();
		
	i = 0;
	while(i < game->hgt)
	{
		free(visit[i]);
		i++;
	}
	return(visit);
}

void check_path(t_game *game, int i, int j, int **visit)//flufli
{
	if (i < 0 || i >= game->hgt || j < 0 || j >= game->wth
		|| visit[i][j] || game->map[i][j] == '1')
		return;

	visit[i][j] = 1;

    // Si la posición actual es el punto de salida, marcar que se encontró un camino y retornar
	if (game->map[i][j] == 'E')
	{
		game->exit = 1;
		return;
	}

    // Continuar la búsqueda en las posiciones adyacentes
	check_path(game, i - 1, j, visit); // arriba
	check_path(game, i + 1, j, visit); // abajo
	check_path(game, i, j - 1, visit); // izquierda
	check_path(game, i, j + 1, visit); // derecha
}


void check_collectibles(t_game *game, int **visit)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < game->hgt)
	{
		j = 0;
		while(j < game->wth)
		{
			if (game->map[i][j] == 'C' && visit[i][j] == 1)
			{
				game->collectibles--;
				if (game->collectibles == 0)
				{
					game->exit = 1;
					return;
				}
			}
			j++;
		}
		i++;
	}
}