/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_uint16t.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegendr <rlegendr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:42:06 by cpieri            #+#    #+#             */
/*   Updated: 2020/11/30 16:09:03 by rlegendr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int.h"

uint16_t	swap_uint16t(uint16_t nb)
{
    return (nb << 8) | (nb >> 8 );
}
