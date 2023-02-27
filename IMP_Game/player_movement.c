/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:33:15 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/27 15:47:49 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	kill_player(t_game *game)
{
	game->player.tile = NULL;
}

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
}

void	move_to_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

void	pick_collect(t_game *game, t_tile *tile)
{
	game->collects = game->collects - 1;
	tile->type = PLAYER;
	game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

void	move_to_exit(t_game *game)
{
	remove_player(game);
	game->collects = -1;
	kill_player(game);
}
