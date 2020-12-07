/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:45:23 by matheme           #+#    #+#             */
/*   Updated: 2020/12/04 14:17:27 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"


static int ft_strcmp_magic(struct symtab_command *sym, int *index, int i, char *ptr)
{
	void	*symoff;
	void	*stroff;
	int		magic;

	symoff = (void*)ptr + LITTLE_BIG(sym->symoff);
	stroff = (void*)ptr + LITTLE_BIG(sym->stroff);
	magic = *(int*)ptr;
	if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
	{
		return (ft_strcmp(stroff + LITTLE_BIG((((struct nlist_64 *)symoff)[index[i]].n_un.n_strx)),
			stroff + LITTLE_BIG((((struct nlist_64 *)symoff)[index[i - 1]].n_un.n_strx))));
	}
	return (ft_strcmp(stroff + LITTLE_BIG((((struct nlist *)symoff)[index[i]].n_un.n_strx)),
		stroff + LITTLE_BIG((((struct nlist *)symoff)[index[i - 1]].n_un.n_strx))));
}

int	*sort_nlist(struct symtab_command *sym, char *ptr)
{

	int				*index;
	int				nsyms;
	int				i;
	int				tmp;

	nsyms = LITTLE_BIG(sym->nsyms);
	index = malloc(sizeof(int) * nsyms);
	i = -1;
	while (++i < nsyms)
		index[i] = i;
	i = 1;
	while (i < nsyms)
	{
		if (ft_strcmp_magic(sym, index, i, ptr) < 0)
		{
			tmp = index[i - 1];
			index[i - 1] = index[i];
			index[i] = tmp;
			i = i > 1 ? i - 2 : 0;
		}
		i++;
	}
	return (index);
}
