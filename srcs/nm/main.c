/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:12:05 by matheme           #+#    #+#             */
/*   Updated: 2020/11/24 14:52:37 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int ac, char **av) {

	struct stat *buffer = (struct stat*)malloc(sizeof(*stat));

	if (ac == 2) {
		int fd = open(av[1], O_RDONLY);
		fstat(fd, buffer);
		printf("%-36s %lds\n","time of file creation(birth)", buffer->st_birthtimespec.tv_sec);
		printf("%-36s %lds\n","time of last data modification", buffer->st_mtimespec.tv_sec);
		printf("%-36s %lds\n","time of last status change", buffer->st_ctimespec.tv_sec);
		printf("%-36s %lds\n","time of last access", buffer->st_atimespec.tv_sec);


		printf("%-36s %hu\n","[XSI] Number of hard links", buffer->st_nlink);
		printf("%-36s %p\n","RESERVED: DO NOT USE!", buffer->st_qspare);
		printf("%-36s %d\n","RESERVED: DO NOT USE!", buffer->st_lspare);

		printf("%-36s %llu\n","[XSI] File serial number", buffer->st_ino);
		printf("%-36s %u\n","file generation number", buffer->st_gen);
		printf("%-36s %d\n","[XSI] Device ID", buffer->st_rdev);
		printf("%-36s %d\n","[XSI] ID of device containing file", buffer->st_dev);
		printf("%-36s %u\n","[XSI] Group ID of the file", buffer->st_gid);
		printf("%-36s %u\n","[XSI] User ID of the file", buffer->st_uid);
		printf("%-36s %hu\n","[XSI] Mode of file (see below)", buffer->st_mode);
		printf("%-36s %u\n","user defined flags for file", buffer->st_flags);

		printf("%-36s %d\n","optimal blocksize for I/O", buffer->st_blksize);
		printf("%-36s %lld\n","blocks allocated for file", buffer->st_blocks);
		printf("%-36s %lld\n","[XSI] file size, in bytes", buffer->st_size);
		return (1);
	}

	return (0);
}
