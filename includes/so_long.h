/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:48:59 by afournie          #+#    #+#             */
/*   Updated: 2025/12/09 18:28:11 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MLX
# define BUFFER_SIZE 1024

# include "../libft/libft.h"
# include "../minilibx/minilibx-linux/mlx.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;

	void	*tex_wall;
	void	*tex_floor;
	void	*tex_player;
	void	*tex_collect;
	void	*tex_exit;

	char	**map;
	int		width;
	int		height;
	int		tile_size;

	int		player_x;
	int		player_y;

	int		collectibles;
	int		collected;
	int		moves;
}			t_game;

char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int i);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_next_line(int fd);
void		get_map_info(t_game *game, char *map_path);
char		**expand_map(char **old_map, int old_size, char *new_line);
void		get_map_size(t_game *game);

#endif
