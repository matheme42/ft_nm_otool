/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegendr <rlegendr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:30:48 by rlegendr          #+#    #+#             */
/*   Updated: 2020/12/07 13:45:42 by rlegendr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_int.h"

uint64_t swap_byte(uint64_t k, size_t size)
{	
	// ft_printf("		swap byte\n				k = %#b, size = %d\n", k, size);
	if (size == sizeof(uint8_t))
		k = swap_uint8t((uint8_t) k);
	else if (size == sizeof(uint16_t))
		k = swap_uint16t((uint16_t) k);
	else if (size == sizeof(uint32_t))
		k = swap_uint32t((uint32_t) k);
	else if (size == sizeof(uint64_t))
		k = swap_uint64t((uint64_t) k);
	// ft_printf("		fin swap byte\n				k = %#b, size = %d\n", k, size);
	
	return (k);
}