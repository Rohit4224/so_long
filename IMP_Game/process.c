/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:27:05 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/27 15:43:13 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_to_empty(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game);
void	pick_collect(t_game *game, t_tile *tile);

// fa ritornare il gioco al suo stato originale
// ciclo la matrice
// ciclo finche non arrivo all'ultimo tile
// ripristino il loro tipo
int	reset(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->tilemap[y] != NULL)
	{
		x = 0;
		while (game->tilemap[y][x].type != 0)
		{
			game->tilemap[y][x].type = game->tilemap[y][x].og_type;
			if (game->tilemap[y][x].type == PLAYER)
			{
				game->player.tile = &game->tilemap[y][x];
			}
			x++;
		}
		y++;
	}
	game->moves = 0;
	game->collects = game->og_collects;
	return (0);
}

//muove il giocatore al blocco faciendo cio che ha bisogno basandosi sul tipo
t_bool	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		pick_collect(game, tile);
	else if (tile->type == EXIT && game->collects == 0)
		move_to_exit(game);
	return (TRUE);
}

//gestione tasti.chiamato ogni volta che premi un tasto
int	process(int key, t_game *game)
{
	t_bool	moved;

	if (key == ESC)
		end_program(game);
	else if (key == RESET)
		return (reset(game));
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		moved = move_to(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right);
	else
		return (0);
	if (moved != 0)
	{
		game->moves = game->moves + 1;
		printf("key pressed = %d\n", game->moves);
	}
	return (1);
}
