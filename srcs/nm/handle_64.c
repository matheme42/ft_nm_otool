/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:33:23 by matheme           #+#    #+#             */
/*   Updated: 2020/12/08 17:27:33 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int print_output(struct symtab_command *sym, char *ptr, long long *isect) {
	int				i;
	char			*name; 
	struct nlist_64	*array;
	int				*sort_index;
	char			type;

	i = 0;
	array = (void*)ptr + LITTLE_BIG(sym->symoff);
	sort_index = sort_nlist(sym, ptr);
	if (!sort_index) {
		return (TruncateObject);
	}
	while(i < LITTLE_BIG(sym->nsyms)) {
		if ((array[sort_index[i]].n_type & N_STAB) != 0) {
			i++;
			continue ;
		}

		type = get_symbol(array[sort_index[i]].n_type, isect, array[sort_index[i]].n_sect);
		type = !(array[sort_index[i]].n_type & N_EXT) ? type + 32 : type;
		if (type == 'i' || type == 'I')/// chaterton ++
		{
			char type2 = get_symbol(array[sort_index[i + 1]].n_type, isect, array[sort_index[i + 1]].n_sect);
			type2 = !(array[sort_index[i + 1]].n_type & N_EXT) ? type2 + 32 : type2;
			name = (void*)ptr + LITTLE_BIG(sym->stroff) + LITTLE_BIG(array[sort_index[i + 1]].n_un.n_strx);
			if ((LITTLE_BIG(array[sort_index[i + 1]].n_value) != 0 && type2 != 'I' && type2 != 'i') || type2 == 'T' || type2 == 't') {
				ft_printf("%.16llx %c ", LITTLE_BIG(array[sort_index[i + 1]].n_value), type2);
				ft_print_until_non_printable(name);
				ft_putstr("");
				ft_putchar('\n');
			} else
			{
				ft_printf("%16s %c ", "", type2);
				ft_print_until_non_printable(name);
				if (type2 == 'i' || type2 == 'I') {
					ft_printf(" (indirect for %s)", name);
				}
				ft_putchar('\n');
			}
			i++;
		}

		name = (void*)ptr + LITTLE_BIG(sym->stroff) + LITTLE_BIG(array[sort_index[i]].n_un.n_strx);
		if ((LITTLE_BIG(array[sort_index[i]].n_value) != 0 && type != 'I' && type != 'i') || type == 'T' || type == 't') {
			ft_printf("%.16llx %c ", LITTLE_BIG(array[sort_index[i]].n_value), type);
			ft_print_until_non_printable(name);
			ft_putstr("");
		 	ft_putchar('\n');
		} else
		{
			ft_printf("%16s %c ", "", type);
			ft_print_until_non_printable(name);
			if (type == 'i' || type == 'I') {
				ft_printf(" (indirect for %s)", name);
			}
		 	ft_putchar('\n');
		}
		i++;
	}
	return (Success);
}

static void get_info_segment(struct segment_command_64 *seg, long long *isect, char *ptr)
{
	struct section_64 *sect = (void *)seg + sizeof(*seg);
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

int		handle_64(void *ptr)
{
	int			                    ncmds;
	int			                    i;
	struct		mach_header_64		*header;
	struct		load_command		*lc;
	long long                  		isect;
	int								error;

	header = (struct mach_header_64 *)  ptr;
	ncmds = LITTLE_BIG(header->ncmds);
	lc = (void *) ptr + sizeof(*header);
	isect = 0;
	i = 0;
	if (LITTLE_BIG(header->sizeofcmds) > g_file()->size) {
		return (WrongFile);
	}
	while (i < ncmds) {
		if (LITTLE_BIG(lc->cmd) == LC_SEGMENT_64) {
			get_info_segment((struct segment_command_64 *) lc, &isect, ptr);
		}
		else if (LITTLE_BIG(lc->cmd) == LC_SYMTAB) {
			if ((error = print_output((struct symtab_command *) lc, ptr, &isect)))
				return (error);
		}
		if ((void*)lc + LITTLE_BIG(lc->cmdsize) > ptr + g_file()->size)
			break ;
		lc = (void*)lc + LITTLE_BIG(lc->cmdsize);
		i++;
	}
	if ((void*)header + LITTLE_BIG(header->sizeofcmds) + sizeof(*header) != (void*)lc) {
		return (CorruptBin);
	}
	return (Success);
}
