/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 08:12:02 by matheme           #+#    #+#             */
/*   Updated: 2020/12/04 16:23:13 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

/// la fonction fat_handle gere a la fois les FAT_32 et les FAT_64
/// que l'on soit en little or big endian

void print_name(const char *cpu_name) {
	dprintf(1, "\n%s (for architecture %s):\n", g_file()->name, cpu_name);
}


int	check_arch_86_64(void *ptr) {
	struct fat_header	*header;
	void				*arch;
	char				*cpu_name;
	int					error;
	int					i;

	header = (struct fat_header *)ptr;
	arch = (void*)ptr + sizeof(*header);
	i = -1;
	while (++i < LITTLE_BIG(header->nfat_arch))
	{
		if (header->magic == FAT_CIGAM_64 || header->magic == FAT_MAGIC_64)
		{
			cpu_name = get_arch_info_from_cpu_type(LITTLE_BIG(((struct fat_arch_64 *)arch)[i].cputype), LITTLE_BIG(((struct fat_arch_64 *)arch)[i].cpusubtype)).name;
			if (!ft_strcmp(cpu_name, "x86_64"))
				return (i - 1);
		}
		else
		{
			cpu_name = get_arch_info_from_cpu_type(LITTLE_BIG(((struct fat_arch *)arch)[i].cputype), LITTLE_BIG(((struct fat_arch *)arch)[i].cpusubtype)).name;
			if (!ft_strcmp(cpu_name, "x86_64"))
				return (i - 1);
		}
	}
	return -1;
}

int		fat_handle(void *ptr)
{
	struct fat_header	*header;
	void				*arch;
	int					i;
	int					error;
	char				*cpu_name;

	header = (struct fat_header *)ptr;
	arch = (void*)ptr + sizeof(*header);
	i = check_arch_86_64(ptr);
	while (++i < LITTLE_BIG(header->nfat_arch))
	{
		if (header->magic == FAT_CIGAM_64 || header->magic == FAT_MAGIC_64)
		{
			cpu_name = get_arch_info_from_cpu_type(LITTLE_BIG(((struct fat_arch_64 *)arch)[i].cputype), LITTLE_BIG(((struct fat_arch_64 *)arch)[i].cpusubtype)).name;
			if (ft_strcmp(cpu_name, "x86_64"))
				print_name(cpu_name);
			if ((error = nm((char*)ptr + LITTLE_BIG(((struct fat_arch_64 *)arch)[i].offset))))
				return (error);
			if (!ft_strcmp(cpu_name, "x86_64"))
				break ;
		}
		else
		{
			cpu_name = get_arch_info_from_cpu_type(LITTLE_BIG(((struct fat_arch *)arch)[i].cputype), LITTLE_BIG(((struct fat_arch *)arch)[i].cpusubtype)).name;
			if (ft_strcmp(cpu_name, "x86_64"))
				print_name(cpu_name);
			if ((error = nm((char*)ptr + LITTLE_BIG(((struct fat_arch *)arch)[i].offset))))
				return (error);
			if (!ft_strcmp(cpu_name, "x86_64"))
				break ;
		}
	}
	return (Success);
}
