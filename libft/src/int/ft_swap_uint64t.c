/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_uint64t.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegendr <rlegendr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:42:06 by cpieri            #+#    #+#             */
/*   Updated: 2020/11/30 13:13:20 by rlegendr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int.h"

uint64_t	swap_uint64t(uint64_t nb)
{
	nb = (nb & 0x00000000FFFFFFFF) << 32 | (nb & 0xFFFFFFFF00000000) >> 32;
	nb = (nb & 0x0000FFFF0000FFFF) << 16 | (nb & 0xFFFF0000FFFF0000) >> 16;
	nb = (nb & 0x00FF00FF00FF00FF) << 8 | (nb & 0xFF00FF00FF00FF00) >> 8;
	return (nb);
}
