/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:41:35 by afournie          #+#    #+#             */
/*   Updated: 2025/12/10 17:37:39 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_textures(t_game *game)
{
	int	w;
	int	h;

	game->tex_wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &w,
			&h);
	game->tex_floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&w, &h);
	game->tex_player_front = mlx_xpm_file_to_image(game->mlx,
			"./textures/player_front.xpm", &w, &h);
	game->tex_player_back = mlx_xpm_file_to_image(game->mlx,
			"./textures/player_back.xpm", &w, &h);
	game->tex_player_left = mlx_xpm_file_to_image(game->mlx,
			"./textures/player_left.xpm", &w, &h);
	game->tex_player_right = mlx_xpm_file_to_image(game->mlx,
			"./textures/player_right.xpm", &w, &h);
	game->tex_collect = mlx_xpm_file_to_image(game->mlx,
			"./textures/collect.xpm", &w, &h);
	game->tex_exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &w,
			&h);
	game->tile_size = w;
}
