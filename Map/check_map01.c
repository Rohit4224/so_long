/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:21:24 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/25 16:56:22 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

//ritorna quanti caratteri ci sono in <str>
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

//controllo se ho un elemento di gioco
int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (TRUE);
	return (FALSE);
}

//verifico che il carattere c non sia uguale a p
//bool di default FALSE c e diverso da checker(primo caso)
//nel caso e vero diveta TRUE e nel secondo ciclo se si avvera la condizione
//ritorna FALSE
int	valid_uniquechar(char c, char checker, t_bool *bool)
{
	if (c == checker && *bool == FALSE)
		*bool = TRUE;
	else if (c == checker && *bool == TRUE)
		return (FALSE);
	return (TRUE);
}

//controllo il primo o l'ultimo x/y e vedo se e diverso da 1
//se e diverso ritorno FALSE altrimenti TRUE
int	valid_border(char c, t_vector point, t_vector size)
{
	if (point.y == 0 || point.x == 0
		|| point.y == size.y - 1 || point.x == size.x -1)
	{
		if (c != '1')
		{
			return (FALSE);
		}
	}
	return (TRUE);
}
