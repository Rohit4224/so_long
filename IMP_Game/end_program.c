/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:09:51 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/24 18:59:13 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;
	t_tile	**b;

	b = game->backup;
	tilemap = game->tilemap;
	while (*tilemap != NULL)
	{
		free(*b);
		free(*tilemap);
		tilemap++;
		b++;
	}
}

void	free_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall_imgs.block);
	mlx_destroy_image(game->mlx, game->wall_imgs.up_left);
	mlx_destroy_image(game->mlx, game->wall_imgs.up);
	mlx_destroy_image(game->mlx, game->wall_imgs.up_right);
	mlx_destroy_image(game->mlx, game->wall_imgs.right);
	mlx_destroy_image(game->mlx, game->wall_imgs.down_right);
	mlx_destroy_image(game->mlx, game->wall_imgs.down);
	mlx_destroy_image(game->mlx, game->wall_imgs.down_left);
	mlx_destroy_image(game->mlx, game->wall_imgs.left);
	mlx_destroy_image(game->mlx, game->player.idle_img_0);
	mlx_destroy_image(game->mlx, game->collects_imgs.img_0);
	mlx_destroy_image(game->mlx, game->door_open_img);
	mlx_destroy_image(game->mlx, game->door_close_img);
}

// libera la memoria e esce
int	end_program(t_game *game)
{
	free_tilemap(game);
	free(game->tilemap);
	free(game->backup);
	free_image(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
