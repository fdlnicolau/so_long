/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:04:14 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/30 13:03:36 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void check_walls(t_game game)
{
	int rows;

	rows = 0;

	game.map = 0;

/* 	while (game->map[0][1] != NULL)
		rows++; */
}

