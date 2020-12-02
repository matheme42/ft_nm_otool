/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 08:12:02 by matheme           #+#    #+#             */
/*   Updated: 2020/12/02 17:38:13 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		fat_handle_32(void *ptr)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	int					i;
	int					error;

	header = (struct fat_header *)ptr;
	arch = (void*)ptr + sizeof(*header);
	i = -1;
	while (++i < swap_uint32t(header->nfat_arch))
	{
		if ((error = nm((char*)ptr + swap_uint32t(arch[i].offset))))
		{
			return (error);
		}
	}
	return (Success);
}

int		fat_handle_64(void *ptr)
{
	struct fat_header	*header;
	struct fat_arch_64	*arch;
	int					i;
	int					error;

	header = (struct fat_header *)ptr;
	arch = (void*)ptr + sizeof(*header);
	i = -1;
	while (++i < swap_uint32t(header->nfat_arch))
	{
		if ((error = nm((char*)ptr + swap_uint32t(arch[i].offset))))
		{
			return (error);
		}
	}
	return (Success);
}
