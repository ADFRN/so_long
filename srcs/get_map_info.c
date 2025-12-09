/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:03:19 by afournie          #+#    #+#             */
/*   Updated: 2025/12/09 18:48:43 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**expand_map(char **old_map, int old_size, char *new_line)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (old_size + 2));
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
		size++;
		map = get_next_line(fd);
	}
	size = -1;
	while (game->map[size++])
		ft_printf("%s", game->map[size]);
}

void	get_map_size(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	width = ft_strlen(game->map[0]);
	while (game->map[height])
		height++;
	game->height = height;
	game->width = width;

	ft_printf("h : %i\n", height);
	ft_printf("w : %i\n", width);
}
