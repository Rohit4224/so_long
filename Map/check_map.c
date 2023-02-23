/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:12:04 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/23 18:12:05 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ritorn 1 se il file e valido
//altrimenti esegue test dove il file puo dare errore

#include "map.h"

int	valid_file(int argc, char *file)
{
	if (argc == 1)
		return (error("There should be one another argument"));
	if (argc > 2)
		print_warning("Only first argument will be taken into consideration");
	if (ft_cmp(file, ".ber") == 0)
		return (error("\".ber\" file should be there, but it isn't"));
	return (1);
}
