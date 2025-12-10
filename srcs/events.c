/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:56:30 by afournie          #+#    #+#             */
/*   Updated: 2025/12/10 19:52:57 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void *p)
{
	t_game	*game;

	game = (t_game *)p;
	free_struct(game);
	exit(0);
	return (0);
}

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

void	check_events(t_game *game)
{
	char	cell;

	cell = game->map[game->player_y][game->player_x];
	if (cell == COLLECTIBLE)
	{
		game->collected += 1;
		game->map[game->player_y][game->player_x] = '0';
		ft_printf("Collecte : %i/%i\n", game->collected, game->collectibles);
	}
	else if (cell == EXIT)
	{
		ft_printf("ggwp %i moves\n", game->moves);
		close_window(game);
	}
}


