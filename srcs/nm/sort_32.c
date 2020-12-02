/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_32.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:21:03 by matheme           #+#    #+#             */
/*   Updated: 2020/12/02 17:34:35 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int	*sort_nlist(struct symtab_command *sym, char *ptr)
{
	struct nlist	*array;
	int				*index;
	int				i;
	int				tmp;

	array = (void*)ptr + sym->symoff;
	index = malloc(sizeof(int) * sym->nsyms);
	i = -1;
	while (++i < sym->nsyms)
		index[i] = i;
	i = 1;
	while (i < sym->nsyms)
	{
		if (ft_strcmp((void*)ptr + sym->stroff + array[index[i]].n_un.n_strx,
			(void*)ptr + sym->stroff + array[index[i - 1]].n_un.n_strx) < 0)
		{
			tmp = index[i - 1];
			index[i - 1] = index[i];
			index[i] = tmp;
			if (i > 1)
				i = i - 2;
		}
		i++;
	}
	return (index);
}
