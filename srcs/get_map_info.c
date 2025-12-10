/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:03:19 by afournie          #+#    #+#             */
/*   Updated: 2025/12/10 19:17:41 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**expand_map(char **old_map, int old_size, char *new_line)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (old_size + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[old_size] = new_line;
	new_map[old_size + 1] = NULL;
	free(old_map);
	return (new_map);
}

void	count_collectibles(const char *s, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == COLLECTIBLE)
			j++;
		i++;
	}
	game->collectibles = game->collectibles + j;
}

void	get_map_info(t_game *game, char *map_path)
{
	int		fd;
	char	*map;
	int		size;

	size = 0;
	game->map = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return ;
	map = get_next_line(fd);
	while (map)
	{
		game->map = expand_map(game->map, size, map);
		count_collectibles(map, game);
		size++;
		map = get_next_line(fd);
	}
	close(fd);
}

void	get_map_size(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	if (!game->map || !game->map[0])
	{
		ft_printf("Error: map is empty or invalid\n");
		exit(1);
	}
	width = ft_strlen(game->map[0]);
	if (width > 0 && game->map[0][width - 1] == '\n')
		width--;
	while (game->map[height])
		height++;
	game->height = height;
	game->width = width;
}
