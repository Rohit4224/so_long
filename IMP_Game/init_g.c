/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:36:58 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/27 14:59:03 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../Map/map.h"

void	img_open(t_game *game);
t_tile	**create_tilemap(char **map, t_game *game);

t_tile	**init_m(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (valid_file(argc, argv[1]) == 0)
		return (NULL);
	map = read_m(argv[1]);
	if (map == NULL)
		return (NULL);
	if (valid_map(map) == FALSE)
	{
		ft_free_chartable(map);
		return (NULL);
	}
	tilemap = create_tilemap(map, game);
	game->backup = ft_continue(game->backup, map);
	ft_free_chartable(map);
	if (tilemap == NULL)
		return (NULL);
	return (tilemap);
}

void	init_g(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x,
			game->wndw_size.y,
			"so_long");
	img_open(game);
	if (possible_win(game->backup) == FALSE)
	{
		error("YOU CANNOT WIN THE GAME");
		end_program(game);
	}
}

t_bool	begin(t_game *game, int argc, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = init_m(argc, argv, game);
	if (game->tilemap == NULL)
		return (FALSE);
	game->og_collects = game->collects;
	init_g(game);
	return (TRUE);
}
