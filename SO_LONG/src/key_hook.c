/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:12:29 by lnicolau          #+#    #+#             */
/*   Updated: 2024/06/10 20:01:39 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_key_hook(mlx_key_data_t keydata, void *game)
{
	t_game *data;
	data = (t_game *)game;
	mlx_key_hook(keydata, data);
	key_hook(keydata, data);
	mlx_hook(game->window, 2, 0, key_hook, game);
	//mlx_hook(game->window, 17, 0, close_window, game);
}

void key_hook(mlx_key_data_t keydata, t_game *data)
{
	printf("key: %d, action: %d\n", keydata.key, keydata.action);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		move_player(data, UP, data->player_y - 1, data->player_x);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		move_player(data, DOWN, data->player_y + 1, data->player_x);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		move_player(data, RIGHT, data->player_y, data->player_x + 1);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		move_player(data, LEFT, data->player_y, data->player_x - 1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		move_player(EXIT_SUCCESS);
}