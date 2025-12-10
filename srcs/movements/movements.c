/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:56:17 by afournie          #+#    #+#             */
/*   Updated: 2025/12/10 17:33:56 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	press_key(int key, void *p)
{
	if (key == ECHAP_KEY)
		close_window((t_game *)p);
	if (key == W_KEY || key == UARROW_KEY)
		move_up((t_game *)p);
	if (key == A_KEY || key == LARROW_KEY)
		move_left((t_game *)p);
	if (key == S_KEY || key == DARROW_KEY)
		move_down((t_game *)p);
	if (key == D_KEY || key == RARROW_KEY)
		move_right((t_game *)p);
	return (0);
}

void	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != WALL)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tex_floor,
			game->player_x * game->tile_size, game->player_y * game->tile_size);
		game->player_y = game->player_y - 1;
		mlx_put_image_to_window(game->mlx, game->win, game->tex_player_back,
			game->player_x * game->tile_size, game->player_y * game->tile_size);
	}
}


void	move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != WALL)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tex_floor,
			game->player_x * game->tile_size, game->player_y * game->tile_size);
		game->player_x = game->player_x - 1;
		mlx_put_image_to_window(game->mlx, game->win, game->tex_player_left,
			game->player_x * game->tile_size, game->player_y * game->tile_size);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != WALL)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tex_floor,
			game->player_x * game->tile_size, game->player_y * game->tile_size);
		game->player_y = game->player_y + 1;
		mlx_put_image_to_window(game->mlx, game->win, game->tex_player_right,
			game->player_x * game->tile_size, game->player_y * game->tile_size);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != WALL)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tex_floor,
			game->player_x * game->tile_size, game->player_y * game->tile_size);
		game->player_x = game->player_x + 1;
		mlx_put_image_to_window(game->mlx, game->win, game->tex_player_front,
			game->player_x * game->tile_size, game->player_y * game->tile_size);
	}
}
