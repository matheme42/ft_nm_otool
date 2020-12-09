/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:05:48 by matheme           #+#    #+#             */
/*   Updated: 2020/12/09 13:59:56 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static char	get_section_letter(long long *isect, uint8_t n)
{
	if (n == (*isect & Bss) >> BssOffset)
	{
		return ('B');
	}
	if (n == (*isect & Data) >> DataOffset)
	{
		return ('D');
	}
	if (n == (*isect & Text) >> TextOffset)
	{
		return ('T');
	}
	return ('S');
}

char		get_symbol(u_int8_t symbol, long long *isect, uint8_t n)
{
	symbol = symbol & N_TYPE;
	if (symbol == N_UNDF)
		return ('U');
	if (symbol == N_ABS)
		return ('A');
	if (symbol == N_SECT)
		return (get_section_letter(isect, n));
	if (symbol == N_INDR)
		return ('I');
	return ('-');
}
