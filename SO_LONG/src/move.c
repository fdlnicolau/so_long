/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:19:21 by lnicolau          #+#    #+#             */
/*   Updated: 2024/06/10 19:57:12 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	calculate_new_position(t_game *game, int direction, int	*new_x, int	*new_y)
{
	*new_x = game->player_x;
	*new_y = game->player_y;
	if (direction == UP)
		(*new_y)--;
	else if (direction == DOWN)
		(*new_y)++;
	else if (direction == RIGHT)
		(*new_x)++;
	else if (direction == LEFT)
		(*new_x)--;
	printf("Calculated new position: new_x = %d, new_y = %d\n", *new_x, *new_y);
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	char	cell;

	if (new_x < 0 || new_x >= game->cols || new_y < 0 || new_y >= game->rows)
		return ;
	cell = game->map[new_y][new_x];
	if (cell == '1')
		return ;
	if (cell == 'C')
	{
		game->map[new_y][new_x] != '1';
		game->collectibles--;
		if (game->collectibles == 0)
			game->exit = 1;
	}
    game->map[game->player_y][game->player_x] = '0';
    game->player_x = new_x;
    game->player_y = new_y;
    game->map[new_y][new_x] = 'P';
}

void	move_player(t_game *game, int direction)
{
	int	new_x;
	int	new_y;

	calculate_new_position(game, direction, &new_x, &new_y);
	printf("new_x: %d, new_y: %d\n", new_x, new_y);
	update_player_position(game, new_x, new_y);
	render_game_state(game);
}

void render_game_state(t_game *game)
{
	int y;
	int x;

	y = 0;
	x = 0;
	mlx_clear_window(game->mlx, game->win_ptr);
	while(y < game->hgt)
	{
		y++;
		while(x < game->wth)
		{
			x++;
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win_ptr, game->wall.img, x * 64, y * 64);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win_ptr, game->floor.img, x * 64, y * 64);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win_ptr, game->player.img, x * 64, y * 64);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win_ptr, game->exit.img, x * 64, y * 64);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win_ptr, game->collectible.img, x * 64, y * 64);
		}
	}
}

void game_loop(t_game *game)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, init_key_hook, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, close_window, game);
	mlx_loop(game->mlx);
}
