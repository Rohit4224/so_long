/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:35:55 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/22 15:46:34 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.h"
#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	game;

	if (start(&game, argc, argv) == FALSE)
		return (0);
	mlx_hook(game.window, 2, 1L << 0, input, (void *)&game);
	mlx_hook(game.window, 17, 1L << 4, end_program, (void *)&game);
	//mlx_loop_hook(game.mlx, update, (void*)&game);
	mlx_loop(game.mlx);
	return (0);
}
