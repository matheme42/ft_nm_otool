/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:38:35 by matheme           #+#    #+#             */
/*   Updated: 2020/12/07 15:54:31 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

t_file	*g_file(void)
{
	static t_file *file;

	if (file == NULL)
	{
		file = malloc(sizeof(*file));
		ft_bzero(file, sizeof(file));
	}
	return (file);
}
