/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:01:41 by matheme           #+#    #+#             */
/*   Updated: 2020/12/04 17:00:12 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void print_output(struct symtab_command *sym, char *ptr, long long *isect) {
	int				i;
	char			*name; 
	struct nlist	*array;
	int				*sort_index;
	char			type;

	i = 0;
	array = (void*)ptr + LITTLE_BIG(sym->symoff);
	sort_index = sort_nlist(sym, ptr);
	while(i < LITTLE_BIG(sym->nsyms)) {
		if ((array[sort_index[i]].n_type & N_STAB) != 0) {
			i++;
			continue ;
		}

		name = (void*)ptr + LITTLE_BIG(sym->stroff) + LITTLE_BIG(array[sort_index[i]].n_un.n_strx);
		type = get_symbol(array[sort_index[i]].n_type, isect, array[sort_index[i]].n_sect);
		type = !(array[sort_index[i]].n_type & N_EXT) ? type + 32 : type;
		if (LITTLE_BIG(array[sort_index[i]].n_value) != 0 || type == 'T') {
			dprintf(1, "%.8x %c ",(unsigned int)LITTLE_BIG(array[sort_index[i]].n_value), type);
			ft_putnstr(name, ft_strplen(name));
			ft_putchar('\n');
		} else {
			dprintf(1, "%8s %c ","", type);
			ft_putnstr(name, ft_strplen(name));
			ft_putchar('\n');
		 }
		i++;
	}
}

static void get_info_segment(struct segment_command *seg, long long *isect, char *ptr)
{
	struct section *sect = (void *)seg + sizeof(*seg);
	int i;

	i = 0;

	while (i < LITTLE_BIG(seg->nsects))
	{
		*isect += 1;
		if (!ft_strcmp(sect[i].segname, SEG_TEXT) && !ft_strcmp(sect[i].sectname, SECT_TEXT))
		{
			*isect |= ((*isect & Sect) << TextOffset);
		}
		else if (!ft_strcmp(sect[i].segname, SEG_DATA))
		{
			 !ft_strcmp(sect[i].sectname, SECT_DATA) ? *isect |= ((*isect & Sect) << DataOffset) : 0;
			 !ft_strcmp(sect[i].sectname, SECT_BSS) ? *isect |= ((*isect & Sect) << BssOffset) : 0;
		}
		i++;
	}
}

int		handle_32(void *ptr)
{
	int			                    ncmds;
	int			                    i;
	struct		mach_header			*header;
	struct		load_command		*lc;
	long long                  		isect;

	header = (struct mach_header *)  ptr;
	ncmds = LITTLE_BIG(header->ncmds);
	lc = (void *) ptr + sizeof(*header);
	isect = 0;
	i = 0;
	while (i < ncmds) {
		if (LITTLE_BIG(lc->cmd) == LC_SEGMENT) {
				get_info_segment((struct segment_command *) lc, &isect, ptr);
		}
		else if (LITTLE_BIG(lc->cmd) == LC_SYMTAB) {
			print_output((struct symtab_command *) lc, ptr, &isect);
		}
		lc = (void*)lc + LITTLE_BIG(lc->cmdsize);
		i++;
	}
	if ((void*)header + LITTLE_BIG(header->sizeofcmds) + sizeof(*header) != (void*)lc) {
		return (CorruptBin);
	}
	return (Success);
}
