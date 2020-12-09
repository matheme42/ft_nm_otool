/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:01:41 by matheme           #+#    #+#             */
/*   Updated: 2020/12/09 15:47:10 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static void print_output(char *ptr, struct section *sect, char *arch_name) {
	int i;
	int size;

	ft_printf("Contents of (__TEXT,__text) section");
	i = 0;
	while (i < LITTLE_BIG(sect->size)) {
		if (i % 16 == 0) {
			ft_printf("\n%.8llx\t", (uint64_t)LITTLE_BIG(sect->addr) + i);
		}
		if (!ft_strcmp("ppc", arch_name))
		{
			ft_printf("%.2hhx", *(ptr + LITTLE_BIG(sect->offset) + i));
			if (i % 4 == 3)
			{
				ft_putchar(' ');
			}
		} else
		{
			ft_printf("%.2hhx ", *(ptr + LITTLE_BIG(sect->offset) + i));
		}
		i++;
	}
}

static struct section *get_info_segment(struct segment_command *seg, char *ptr)
{
	struct section *sect = (void *)seg + sizeof(*seg);

	for (int i = 0 ; i < LITTLE_BIG(seg->nsects) ; i++) {
		if (!ft_strcmp(sect[i].segname, SEG_TEXT) && !ft_strcmp(sect[i].sectname, SECT_TEXT)) {
			return (sect + i);
		}
		i++;
	}
	return (NULL);
}

int		handle_32(void *ptr)
{
	int			                    ncmds;
	int			                    i;
	struct		mach_header			*header;
	struct		load_command		*lc;
	struct		section				*sect;
	char							*name;

	header = (struct mach_header *)  ptr;
	ncmds = LITTLE_BIG(header->ncmds);
	lc = (void *) ptr + sizeof(*header);
	i = 0;
	if (LITTLE_BIG(header->sizeofcmds) > g_file()->size) {
		return (WrongFile);
	}
	sect = NULL;
	while (i < ncmds) {
		if (sect == NULL && LITTLE_BIG(lc->cmd) == LC_SEGMENT)
			sect = get_info_segment((struct segment_command *) lc, ptr);
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
