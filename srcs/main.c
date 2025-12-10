/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:46:43 by afournie          #+#    #+#             */
/*   Updated: 2025/12/10 17:36:33 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->tex_floor, x
				* game->tile_size, y * game->tile_size);
			if (game->map[y][x] == WALL)
				mlx_put_image_to_window(game->mlx, game->win, game->tex_wall, x
					* game->tile_size, y * game->tile_size);
			else if (game->map[y][x] == PLAYER)
			{
				game->player_x = x;
				game->player_y = y;
				mlx_put_image_to_window(game->mlx, game->win,
					game->tex_player_front, x * game->tile_size, y
					* game->tile_size);
			}
			else if (game->map[y][x] == COLLECTIBLE)
				mlx_put_image_to_window(game->mlx, game->win, game->tex_collect,
					x * game->tile_size, y * game->tile_size);
			else if (game->map[y][x] == EXIT)
				mlx_put_image_to_window(game->mlx, game->win, game->tex_exit, x
					* game->tile_size, y * game->tile_size);
			x++;
		}
		y++;
	}
}

int	close_window(void *p)
{
	t_game	*game;

	game = (t_game *)p;
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	*map_path;

	if (argc != 2)
		return (0);
	map_path = argv[1];
	game = malloc(sizeof(t_game));
	ft_bzero(game, sizeof(t_game));
	get_map_info(game, map_path);
	get_map_size(game);
	game->mlx = mlx_init();
	mlx_do_key_autorepeaton(game->mlx);
	if (!game->mlx)
	{
		ft_printf("Init KO\n");
		exit(1);
	}
	init_textures(game);
	game->win = mlx_new_window(game->mlx, game->width * game->tile_size,
			game->height * game->tile_size, "SO_LONG");
	if (!game->win)
	{
		ft_printf("Windows KO\n");
		exit(1);
	}
	render_game(game);
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}
