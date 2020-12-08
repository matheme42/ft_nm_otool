/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_until_non_printable.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegendr <rlegendr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:25:08 by rlegendr          #+#    #+#             */
/*   Updated: 2020/12/04 17:25:55 by rlegendr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

void	ft_print_until_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_printable(str[i]))
		{
			ft_putchar(str[i]);
			return ;
		}
		ft_putchar(str[i++]);
	}
}