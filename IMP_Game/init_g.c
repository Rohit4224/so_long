/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:36:58 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/23 15:51:43 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../map/map.h"

t_tile	**init_m(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (valid_file(argc, argv[1]) == 0)
		return (NULL);
	map = read_m(argv[1]);
	if (map == NULL)
		return (NULL);
	

}

t_bool	start(t_game *game, int argc, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = init_m(argc, argv, game);
	if (game->tilemap == NULL)
		return (FALSE);
	init_g(game);
	return (TRUE);
}
