/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   furnish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:15:15 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/25 19:08:50 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_wall(t_tile tile, t_game game, t_vector pos);

//disegna l'immagine sul corrispettivo blocco
static void	draw_image(t_tile tile, t_game game, t_vector pos)
{
	if (tile.type == WALL)
		draw_wall(tile, game, pos);
	else if (tile.type == EXIT)
	{
		if (game.collects != 0)
			mlx_put_image_to_window(game.mlx, game.window,
				game.door_close_img, pos.x, pos.y);
		if (game.collects == 0)
			mlx_put_image_to_window(game.mlx, game.window,
				game.door_open_img, pos.x, pos.y);
	}
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(game.mlx, game.window,
			game.collects_imgs.img_0, pos.x, pos.y);
	else if (tile.type == PLAYER)
		mlx_put_image_to_window(game.mlx, game.window,
			game.player.idle_img_0, pos.x, pos.y);
}

//mette i blocchi della mappa nella finestra
void	furnish(t_game game)
{
	t_tile			tile;
	int				x;
	int				y;

	mlx_clear_window(game.mlx, game.window);
	y = 0;
	while (game.tilemap[y] != NULL)
	{
		x = 0;
		while (game.tilemap[y][x].type != 0)
		{
			tile = game.tilemap[y][x];
			draw_image(tile, game, tile.position);
			x++;
		}
		y++;
	}
}
