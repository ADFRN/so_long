/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verificator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:45:39 by afournie          #+#    #+#             */
/*   Updated: 2026/01/12 14:16:19 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_components(t_game *game)
{
	if (game->collectibles < 1)
		return (
			ft_printf("Error\nThe map must contain at least 1 collectible.\n"),
			EXIT_FAILURE);
	if (game->player_count != 1)
	{
		ft_printf("Error\nThe map must contain only 1 starting position.\n");
		return (EXIT_FAILURE);
	}
	if (game->exit_count != 1)
		return (ft_printf("Error\nThe map must contain only 1 exit.\n"),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_map_rectangular(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->height > i)
	{
		j = 0;
		while (game->map[i][j] != '\n')
			j++;
		if (j != game->width)
			return (ft_printf("Error\nThe map must be rectangular\n"),
				EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_map_walls_inline(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->width > i)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
		{
			ft_printf("Error\nThe map must be enclosed/surrounded by walls.\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_map_walls(t_game *game)
{
	int	i;

	i = 0;
	while (game->height > i)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
		{
			ft_printf("Error\nThe map must be enclosed/surrounded by walls.\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	map_verificator(t_game *game)
{
	if (check_map_rectangular(game))
		return (EXIT_FAILURE);
	if (check_map_walls_inline(game))
		return (EXIT_FAILURE);
	if (check_map_walls(game))
		return (EXIT_FAILURE);
	if (check_map_components(game))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
