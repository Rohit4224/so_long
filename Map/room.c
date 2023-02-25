/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:04:58 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/25 17:10:21 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_tiletype	define_tiletype(char definer);

t_tile	**alloc_backup(char **map)
{
	t_tile	**tilemap;
	int		i;

	tilemap = malloc(sizeof(t_tile *) * (ft_chartable_linecount(map) + 1));
	if (tilemap == NULL)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		tilemap[i] = malloc(sizeof(t_tile) * (ft_strlen(*map) + 1));
		i++;
	}
	return (tilemap);
}

t_tile	**ft_continue(t_tile **backup, char **map)
{
	int	x;
	int	y;

	backup = alloc_backup(map);
	if (backup == NULL)
		return (null_error("malloc error on alloc_backup()"));
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			backup[y][x].type = define_tiletype(map[y][x]);
			x++;
		}
		backup[y][x].type = '\0';
		y++;
	}
	backup[y] = NULL;
	return (backup);
}
