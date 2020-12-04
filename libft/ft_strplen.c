/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strplen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:44:56 by matheme           #+#    #+#             */
/*   Updated: 2020/12/04 17:44:48 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strplen(const char *str)
{
	size_t i;

	i = 0;
	while (ft_isprint(str[i]))
		i++;
	if (str[i] != '\0') {
		i++;
	}
	return (i);
}