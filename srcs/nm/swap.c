/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:45:52 by matheme           #+#    #+#             */
/*   Updated: 2020/12/03 16:51:48 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static uint8_t	swap_uint8t(uint8_t nb)
{
	return ((nb << 4 & 0xff00) | (nb >> 4 & 0x00ff));
}

static uint16_t	swap_uint16t(uint16_t nb)
{
    return (nb << 8) | (nb >> 8 );
}

static uint32_t	swap_uint32t(uint32_t nb)
{
	return ((nb >> 24 & 0xff) | (nb >> 8 & 0xff00) |
		(nb << 8 & 0xff0000) | (nb << 24 & 0xff000000));
}

static uint64_t	swap_uint64t(uint64_t nb)
{
	nb = (nb & 0x00000000FFFFFFFF) << 32 | (nb & 0xFFFFFFFF00000000) >> 32;
	nb = (nb & 0x0000FFFF0000FFFF) << 16 | (nb & 0xFFFF0000FFFF0000) >> 16;
	nb = (nb & 0x00FF00FF00FF00FF) << 8 | (nb & 0xFF00FF00FF00FF00) >> 8;
	return (nb);
}

uint64_t byte_swap(uint64_t k, size_t size)
{
    if (size == sizeof(uint8_t))
        k = swap_uint8t((uint8_t) k);
    else if (size == sizeof(uint16_t))
        k = swap_uint16t((uint16_t) k);
    else if (size == sizeof(uint32_t))
        k = swap_uint32t((uint32_t) k);
    else if (size == sizeof(uint64_t))
        k = swap_uint64t((uint64_t) k);
    return (k);
}