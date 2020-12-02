/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:25:35 by matheme           #+#    #+#             */
/*   Updated: 2020/12/02 17:44:49 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm(char *ptr)
{
	int			(*tab[5])(void *);
	const int	magictab[9] = {MH_MAGIC, MH_CIGAM, MH_MAGIC_64, MH_CIGAM_64,
				FAT_CIGAM, FAT_MAGIC, FAT_MAGIC_64, FAT_CIGAM_64, *(int*)ARMAG};
	int			i;

	tab[0] = handle_32;
	tab[1] = handle_64;
	tab[2] = fat_handle_32;
	tab[3] = fat_handle_64;
	tab[4] = ar_handle;
	i = 0;
	while (i < 9)
	{
		if (*(int *)ptr == magictab[i])
		{
			return (tab[i / 2](ptr));
		}
		i++;
	}
	return (WrongFile);
}
