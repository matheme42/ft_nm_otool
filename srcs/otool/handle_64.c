/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:33:23 by matheme           #+#    #+#             */
/*   Updated: 2020/12/09 14:01:33 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static void print_output(char *ptr, struct section_64 *sect, char *arch_name) {
	int i;
	int size;

	dprintf(1, "Contents of (__TEXT,__text) section");
	i = 0;
	while (i < LITTLE_BIG(sect->size)) {
		if (i % 16 == 0) {
			dprintf(1, "\n%.16llx\t", (uint64_t)LITTLE_BIG(sect->addr) + i);
		}
		if (!ft_strcmp("ppc", arch_name))
		{
			dprintf(1, "%.2hhx", *(ptr + LITTLE_BIG(sect->offset) + i));
			if (i % 4 == 3)
			{
				ft_putchar(' ');
			}
		} else
		{
			dprintf(1, "%.2hhx ", *(ptr + LITTLE_BIG(sect->offset) + i));
		}
		i++;
	}
}

static struct section_64 *get_info_segment(struct segment_command_64 *seg, char *ptr)
{
	struct section_64 *sect = (void *)seg + sizeof(*seg);

	for (int i = 0 ; i < LITTLE_BIG(seg->nsects) ; i++) {
		if (!ft_strcmp(sect[i].segname, SEG_TEXT) && !ft_strcmp(sect[i].sectname, SECT_TEXT)) {
			return (sect + i);
		}
		i++;
	}
	return (NULL);
}

int		handle_64(void *ptr)
{
	int			                    ncmds;
	int			                    i;
	struct		mach_header_64		*header;
	struct		load_command		*lc;
	struct		section_64			*sect;
	char							*name;

	header = (struct mach_header_64 *)  ptr;
	ncmds = LITTLE_BIG(header->ncmds);
	lc = (void *) ptr + sizeof(*header);
	i = 0;
	if (LITTLE_BIG(header->sizeofcmds) > g_file()->size) {
		return (WrongFile);
	}
	sect = NULL;
	while (i < ncmds) {
		if (sect == NULL && LITTLE_BIG(lc->cmd) == LC_SEGMENT_64)
			sect = get_info_segment((struct segment_command_64 *) lc, ptr);
		if ((void*)lc + LITTLE_BIG(lc->cmdsize) > ptr + g_file()->size)
			break ;
		lc = (void*)lc + LITTLE_BIG(lc->cmdsize);
		i++;
	}
	if ((void*)header + LITTLE_BIG(header->sizeofcmds) + sizeof(*header) != (void*)lc)
		return (CorruptBin);
	if (sect != NULL) {
		name = get_arch_info_from_cpu_type(LITTLE_BIG(header->cputype), LITTLE_BIG(header->cpusubtype)).name;
		print_output(ptr, sect, name);
	}
	return (Success);
}
