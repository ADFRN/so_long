/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 19:23:32 by afournie          #+#    #+#             */
/*   Updated: 2025/12/10 19:53:49 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int	y;

	if (!game->map)
		return ;
	y = 0;
	while (game->map[y])
	{
		free(game->map[y]);
		y++;
	}
	free(game->map);
	game->map = NULL;
}

void	destroy_images(t_game *game)
{
	if (game->tex_wall)
		mlx_destroy_image(game->mlx, game->tex_wall);
	if (game->tex_floor)
		mlx_destroy_image(game->mlx, game->tex_floor);
	if (game->tex_player_front)
		mlx_destroy_image(game->mlx, game->tex_player_front);
	if (game->tex_player_back)
		mlx_destroy_image(game->mlx, game->tex_player_back);
	if (game->tex_player_left)
		mlx_destroy_image(game->mlx, game->tex_player_left);
	if (game->tex_player_right)
		mlx_destroy_image(game->mlx, game->tex_player_right);
	if (game->tex_collect)
		mlx_destroy_image(game->mlx, game->tex_collect);
	if (game->tex_exit)
		mlx_destroy_image(game->mlx, game->tex_exit);
}

void	free_struct(t_game *game)
{
	destroy_images(game);
	free_map(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}
