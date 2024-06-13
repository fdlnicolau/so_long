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

void	init_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game *g;
	g = (t_game *) param;
	pos_player(g);
	up_down_key(keydata, g);
	right_left_key(keydata, g);
	mlx_delete_image(g->mlx, g->str);
	g->temp = ft_itoa(g->steps);
	g->str = mlx_put_string(g->mlx, g->temp, g->wth * S - 32, g->hgt * S - 20);
	free(g->temp);

}

void right_left_key(mlx_key_data_t keydata, t_game *g)
{
	if (g->map[g->player_ps[1]][g->player_ps[0] - 1] != '1')
	{
		if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		{
			g->player_x -= S;
			g->player_ps[0]--;
			g->steps++;
		}
	}
	if (g->map[g->player_ps[1]][g->player_ps[0] + 1] != '1')
	{
		if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		{
			g->player_x += S;
			g->player_ps[0]++;
			g->steps++;
		}
	}
}
void up_down_key(mlx_key_data_t keydata, t_game *g)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit_free(EXIT_SUCCESS, g);
	if (g->map[g->player_ps[1] - 1][g->player_ps[0]] != '1')
	{
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		{
			g->player_y -= S;
			g->player_ps[1]--;
			g->steps++;
		}
	}
	if (g->map[g->player_ps[1] + 1][g->player_ps[0]] != '1')
	{
		if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		{
			g->player_y += S;
			g->player_ps[1]++;
			g->steps++;
		}
	}
}


void pos_player(t_game *g)
{
	if (g->map[g->player_ps[1]][g->player_ps[0]] == 'X')
		ft_exit_free(EXIT_SUCCESS, g);
	if (g->map[g->player_ps[1]][g->player_ps[0]] == 'C')
	{
		g->map[g->player_ps[1]][g->player_ps[0]] = 'P';
		ft_pain_colect(g);
	}
	if (g->map[g->player_ps[1]][g->player_ps[0]] == 'E' && !g->player_exit)
		ft_exit_free(EXIT_SUCCESS, g);
}
