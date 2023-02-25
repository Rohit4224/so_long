/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:35:55 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/25 19:08:13 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map/map.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (begin(&game, argc, argv) == FALSE)
		return (0);
	mlx_hook(game.window, 2, 1L << 0, process, (void *)&game);
	mlx_hook(game.window, 17, 0, end_program, (void *)&game);
	mlx_loop_hook(game.mlx, fill_in, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
