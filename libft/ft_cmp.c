/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:37:15 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/23 18:39:40 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int i;
	i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

//ritorna 1 se <name> finisce in <extension> altrimenti 0
int	ft_cmp(char *name, char *end)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);
	if (name_len <= ext_len)
		return (0);
	name = name + name_len - ext_len;
	while (*name != '\0')
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}
