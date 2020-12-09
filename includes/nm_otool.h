/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:37:00 by matheme           #+#    #+#             */
/*   Updated: 2020/12/09 15:43:59 by matheme          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include "ft_printf.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <ar.h>
# include <mach-o/fat.h>
# include <mach-o/swap.h>

#define	TextOffset 16
#define	DataOffset 32
#define	BssOffset 48

#define	Sect 0xFFFF
#define	Text 0xFFFF0000
#define	Data 0xFFFF00000000
#define	Bss 0xFFFF000000000000

#define	Success 0
#define WrongFile 1
#define CorruptBin 2
#define CorruptLibrary 3
#define MalformedFatFile 4
#define TruncateObject 5

typedef enum				e_endian {
	BIG,
	LITTLE,
	UNKNOWN
}							t_endian;


typedef struct 		s_file
{
	char			*programme_name;
	char			*name;
	int				size;
}					t_file;

#define LITTLE_BIG(x) ((*(int*)ptr == FAT_CIGAM || *(int*)ptr == FAT_CIGAM_64 || *(int*)ptr == MH_CIGAM  || *(int*)ptr == MH_CIGAM_64) ? swap_byte(x, sizeof(x)) : x)

typedef struct				s_arch_info
{
	char					*name;
	cpu_type_t				cputype;
	cpu_subtype_t			cpusubtype;
	t_endian				byte_order;
}							t_arch_info;

t_arch_info					get_arch_info_from_cpu_type(cpu_type_t cputype, cpu_subtype_t cpusubtype);

int			nm_otool(char *ptr);

int			ar_handle(void *ptr);
int			fat_handle(void *ptr);
int			handle_32(void *ptr);
int			handle_64(void *ptr);

char		get_symbol(u_int8_t symbol, long long *isect, uint8_t n);

void		print_output_64(struct symtab_command *sym, char *ptr, long long sect_n);

int			*sort_nlist(struct symtab_command *sym, char *ptr);

t_file		*g_file();

#endif
