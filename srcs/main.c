/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:46:43 by afournie          #+#    #+#             */
/*   Updated: 2025/12/09 18:51:57 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_textures(t_game *game)
{
	int	w;
	int	h;

	game->tex_wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &w,
			&h);
	game->tex_floor = mlx_xpm_file_to_image(game->mlx, "./textures/floor.xpm",
			&w, &h);
	game->tex_player = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm",
			&w, &h);
	game->tex_collect = mlx_xpm_file_to_image(game->mlx,
			"./textures/collectible.xpm", &w, &h);
	game->tex_exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &w,
			&h);
	game->tile_size = w;
}

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
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_wall, x
					* game->tile_size, y * game->tile_size);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_player,
					x * game->tile_size, y * game->tile_size);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_collect,
					x * game->tile_size, y * game->tile_size);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_exit, x
					* game->tile_size, y * game->tile_size);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;
	t_data	img;
	char	*map_path;

	if (argc != 2)
		return (0);
	map_path = argv[1];
	game = malloc(sizeof(t_game));
	ft_bzero(game, sizeof(t_game));
	get_map_info(game, map_path);
	get_map_size(game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Init KO\n");
		exit(1);
	}
	init_textures(game);
	game->win = mlx_new_window(game->mlx, 800, 800, "SO_LONG");
	if (!game->win)
	{
		ft_printf("Windows KO\n");
		exit(1);
	}
	img.img = mlx_new_image(game->mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	render_game(game);
	mlx_loop(game->mlx);
	return (0);
}
