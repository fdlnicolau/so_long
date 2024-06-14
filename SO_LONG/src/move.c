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
		game->map[new_y][new_x] = '1';
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
	while(y < game->hgt)
	{
		while(x < game->wth)
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->wall_img, x * 64, y * 64);
			else if (game->map[y][x] == '0')
				mlx_image_to_window(game->mlx, game->floor_img, x * 64, y * 64);
			else if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->player_img, x * 64, y * 64);
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->exit_img, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window	(game->mlx, game->collect_img, x * 64, y * 64);
			x++;	
		}
		y++;
	}
}
