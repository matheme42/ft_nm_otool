/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 08:10:50 by matheme           #+#    #+#             */
/*   Updated: 2020/12/02 17:30:59 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void	print_name(char *file_name, char *name)
{
	printf("\n%s(%s):\n", file_name, name);
}

static int	check_ar_struct(void *ptr)
{
	struct ar_hdr	*header;
	void			*start;

	header = (struct ar_hdr *)(ptr + SARMAG);
	start = ptr;
	ptr = (void*)header + sizeof(*header) + ft_atoi(header->ar_size);
	while (ptr - start < g_file()->size)
	{
		header = (struct ar_hdr *)ptr;
		ptr += ft_atoi(header->ar_size) + sizeof(*header);
	}
	if (ptr - start != g_file()->size)
	{
		return (CorruptLibrary);
	}
	return (Success);
}

int			ar_handle(void *ptr)
{
	struct ar_hdr	*header;
	char			*str;
	int				len;
	void			*start;
	int				error;

	if ((error = check_ar_struct(ptr)))
	{
		return (error);
	}
	header = (struct ar_hdr *)(ptr + SARMAG);
	start = ptr;
	ptr = (void*)header + sizeof(*header) + ft_atoi(header->ar_size);
	while (ptr - start < g_file()->size)
	{
		header = (struct ar_hdr *)ptr;
		str = ptr + sizeof(*header);
		print_name(g_file()->name, str);
		len = ft_strlen(str);
		while (!str[len++])
			;
		nm(str + len - 1);
		ptr += ft_atoi(header->ar_size) + sizeof(*header);
	}
	return (Success);
}
