/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:44:17 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/24 18:59:33 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_wall_up(t_game *game);
void	open_wall_down(t_game *game);

static void	open_player_imgs(t_game *game)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/player/player_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.idle_img_0;
}

static void	open_collect_imgs(t_game *game)
{
	game->collects_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/collect/plant_03.xpm",
			&game->img_size.x, &game->img_size.y);
	game->collects_imgs.current_img = game->collects_imgs.img_0;
}

static void	open_door_imgs(t_game *game)
{
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/door/door_01.xpm",
			&game->img_size.x, &game->img_size.y);
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/door/door_02.xpm",
			&game->img_size.x, &game->img_size.y);
}

void	img_open(t_game *game)
{
	open_wall_up(game);
	open_wall_down(game);
	open_player_imgs(game);
	open_collect_imgs(game);
	open_door_imgs(game);
}
