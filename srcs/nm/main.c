/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:12:05 by matheme           #+#    #+#             */
/*   Updated: 2020/12/02 17:50:01 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void	catch_nm_error(int code)
{
	if (code == WrongFile)
	{
		ft_putstr("nm: ");
		ft_putstr(g_file()->name);
		ft_putstr(" The file was not recognized as a valid object file\n");
	}
	else if (code == CorruptBin)
	{
		ft_putstr("nm: ");
		ft_putstr(g_file()->name);
		ft_putstr("truncated or malformed object (load commands extend past the end of the file)\n");
	}
	else if (code == CorruptLibrary)
	{
		ft_putstr("nm: ");
		ft_putstr("Mach-O universal file: ");
		ft_putstr(g_file()->name);
		ft_putstr(" for architecture x86_64 is not a Mach-O file or an archive file.\n");
	}
}

int			main(int ac, char **av)
{
	int			fd;
	char		*ptr;
	struct stat buf;
	int			i;

	i = 0;
	while (++i < ac || (ac == 1 && i == 1))
	{
		g_file()->name = ac > 1 ? av[i] : "a.out";
		if ((fd = open(g_file()->name, O_RDONLY)) < 0)
		{
			ft_putstr("nm: ");
			ft_putstr(g_file()->name);
			ft_putstr(": No such file or directory.\n");
			continue ;
		}
		if (fstat(fd, &buf) < 0)
		{
			ft_putstr("nm: ");
			ft_putstr("an error has occurred.\n");
			continue ;
		}
		g_file()->size = buf.st_size;
		if ((ptr = mmap(0,  buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		{
			ft_putstr("nm: ");
			ft_putstr(g_file()->name);
			ft_putstr(": Is a directory.\n");
			continue ;
		}
		if (ac > 2)
		{
			printf("\n%s:\n", g_file()->name);
		}
		catch_nm_error(nm(ptr));
		if (munmap(ptr,  buf.st_size) < 0)
		{
			ft_putstr("nm: ");
			ft_putstr("an error has occurred.\n");
			continue ;
		}
	}
	return (EXIT_SUCCESS);
}
