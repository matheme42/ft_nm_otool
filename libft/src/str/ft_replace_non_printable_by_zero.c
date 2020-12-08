/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_non_printable_by_zero.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegendr <rlegendr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:52:32 by rlegendr          #+#    #+#             */
/*   Updated: 2020/12/04 16:57:58 by rlegendr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

void	ft_replace_non_printable_by_zero(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_printable(str[i]))
		{
			str[i] = 0;
			return ;
		}
		i++;	
	}
}