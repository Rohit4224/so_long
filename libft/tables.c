/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:36:56 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/24 19:33:40 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//ritorna il numero di righe divise da '\n'
int	ft_chartable_linecount(char **table)
{
	int	count;

	count = 0;
	while (table[count] != NULL)
		count++;
	return (count);
}

//libero ogni riga della martrice
void	ft_free_chartable(char **table)
{
	char	**t;

	t = table;
	while (*t != NULL)
	{
		free(*t);
		t++;
	}
	free(table);
}
