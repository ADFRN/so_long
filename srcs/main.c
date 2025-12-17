/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:46:43 by afournie          #+#    #+#             */
/*   Updated: 2025/12/17 17:32:04 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Error\nThe program need a map in argument"),
			EXIT_FAILURE);
	game = malloc(sizeof(t_game));
	if (!game)
		return (EXIT_FAILURE);
	ft_bzero(game, sizeof(t_game));
	get_map_info(game, argv[1]);
	get_map_size(game);
	if (!pathfinder(copy_map(game), &(t_pathfinder){0, 0, 0, 0}))
		free_struct(game);
	game->mlx = mlx_init();
	mlx_do_key_autorepeaton(game->mlx);
	init_textures(game);
	game->win = mlx_new_window(game->mlx, game->width * game->tile_size,
			game->height * game->tile_size, "so_long");
	render_game(game);
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
