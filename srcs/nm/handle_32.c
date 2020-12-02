/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:01:41 by matheme           #+#    #+#             */
/*   Updated: 2020/12/02 18:12:44 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void	print_output2(char *name, char type, uint32_t value)
{
	if (value != 0 || type == 'T')
	{
		dprintf(1, "%.16x %c ", value, type);
		ft_putnstr(name, ft_strplen(name));
		ft_putchar('\n');
	}
	else
	{
		dprintf(1, "%16s %c ", "", type);
		ft_putnstr(name, ft_strplen(name));
		ft_putchar('\n');
	}
}

static void	print_output(struct symtab_command *sym, char *ptr, long long *isec)
{
	int				i;
	char			*name;
	struct nlist	*array;
	int				*sort_index;
	char			type;

	i = 0;
	array = (void*)ptr + sym->symoff;
	sort_index = sort_nlist(sym, ptr);
	while (i < sym->nsyms)
	{
		if ((array[sort_index[i]].n_type & N_STAB) != 0 && i++)
			continue ;
		name = (void*)ptr + sym->stroff + array[sort_index[i]].n_un.n_strx;
		type = get_symbol(array[sort_index[i]].n_type, isec,
											array[sort_index[i]].n_sect);
		type = !(array[sort_index[i]].n_type & N_EXT) ? type + 32 : type;
		print_output2(name, type, array[sort_index[i]].n_value);
		i++;
	}
}

static void	get_info_segment(struct segment_command *seg, long long *isect)
{
	struct section	*sect;
	int				i;

	sect = (void *)seg + sizeof(*seg);
	*isect = 0;
	i = 0;
	while (i < seg->nsects)
	{
		*isect += 1;
		if (!ft_strcmp(sect[i].segname, SEG_TEXT) &&
						!ft_strcmp(sect[i].sectname, SECT_TEXT))
			*isect |= ((*isect & Sect) << TextOffset);
		else if (!ft_strcmp(sect[i].segname, SEG_DATA))
		{
			if (!ft_strcmp(sect[i].sectname, SECT_DATA))
				*isect |= ((*isect & Sect) << DataOffset);
			if (!ft_strcmp(sect[i].sectname, SECT_BSS))
				*isect |= ((*isect & Sect) << BssOffset);
		}
		i++;
	}
}

int			handle_32(void *ptr)
{
	int								ncmds;
	int								i;
	struct mach_header				*header;
	struct load_command				*lc;
	long long						isect;

	header = (struct mach_header*)ptr;
	ncmds = header->ncmds;
	lc = (void *)ptr + sizeof(*header);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			get_info_segment((struct segment_command *)lc, &isect);
		if (lc->cmd == LC_SYMTAB)
			print_output((struct symtab_command *)lc, ptr, &isect);
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
	if ((void*)header + header->sizeofcmds + sizeof(*header) != (void*)lc)
		return (CorruptBin);
	return (Success);
}
