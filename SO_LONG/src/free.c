/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 04:37:38 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/26 04:37:38 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void free_game(t_game *game) 
{
	if (game->map) 
	{
		free_map(game);
	}
	ft_clean_image(game);
	if(game->mlx)
	{
		mlx_terminate(game->mlx);
		free(game->mlx);
		exit(write(1, "\n[END_OF_PROGRAM]\n\n", 21));
	}
}

void ft_clean_image(t_game *game)
{
	if (game->floor_img)
		mlx_delete_image(game->mlx, game->floor_img);
	if (game->exit_img)
		mlx_delete_image(game->mlx, game->exit_img);
	if (game->player_img)
		mlx_delete_image(game->mlx, game->player_img);
	if (game->wall_img)
		mlx_delete_image(game->mlx, game->wall_img);
	if (game->collect_img)
		mlx_delete_image(game->mlx, game->collect_img);
	if (game->str)
		mlx_delete_image(game->mlx, game->str);
}

void close_window(t_game *game)
{
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
	exit(0);
}
void free_map(t_game *game)
{
	int i;

	i = 0;
	while (i < game->rows)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void ft_exit_free(int nb_error, t_game *game)
{
	if (nb_error == EXTENSION_NO_BER)
	{
		write(1, "\n[ERROR] La extensión no es \".ber\".\n\n", 37);
		exit(EXIT_FAILURE);
	}
	else if (nb_error == END_OF_PROGRAM)
	{
		free_game(game);
		write(1, "\n[FIN DE PROGRAMA]\n\n", 21);
		exit(EXIT_SUCCESS);
	}
	else if (nb_error == MAP_NOT_CORRECT)
	{
		write(1, "\n[ERROR] Mapa no correcto.\n\n", 28);
		exit(EXIT_FAILURE);
	}
}