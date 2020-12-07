/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:25:35 by matheme           #+#    #+#             */
/*   Updated: 2020/12/07 15:05:16 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		nm_otool(char *ptr)
{
	int			(*tab[5])(void *) = {handle_32, handle_64, fat_handle, fat_handle, ar_handle};
	const int	magictab[9] = {MH_MAGIC, MH_CIGAM, MH_MAGIC_64, MH_CIGAM_64,
				FAT_CIGAM, FAT_MAGIC, FAT_MAGIC_64, FAT_CIGAM_64, *(int*)ARMAG};

	for (int i = 0; i < 9; i++)
		if (*(int *)ptr == magictab[i])
			return (tab[i / 2](ptr));
	return (WrongFile);
}
