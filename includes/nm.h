#ifndef NM_H
# define NM_H

# include "libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <stdio.h>
# include <ar.h>
# include <mach-o/fat.h>
# include <mach-o/swap.h>

#define Success 0
#define WrongFile	1
#define CorruptBin 2
#define CorruptLibrary 3

#define  TextOffset 16
#define  DataOffset 32
#define  BssOffset 48

#define  Sect 0xFFFF
#define  Text 0xFFFF0000
#define  Data 0xFFFF00000000
#define  Bss 0xFFFF000000000000

typedef enum				e_endian {
	BIG,
	LITTLE,
	UNKNOWN
}							t_endian;

#define LITTLE_BIG(x) ((*(int*)ptr == FAT_CIGAM || *(int*)ptr == FAT_CIGAM_64 || *(int*)ptr == MH_CIGAM  || *(int*)ptr == MH_CIGAM_64) ? byte_swap(x, sizeof(x)) : x)

typedef struct 		s_file
{
	char			*name;
	int				size;
}					t_file;

typedef struct				s_arch_info
{
	char					*name;
	cpu_type_t				cputype;
	cpu_subtype_t			cpusubtype;
	t_endian				byte_order;
}							t_arch_info;

t_arch_info					get_arch_info_from_cpu_type(cpu_type_t cputype, cpu_subtype_t cpusubtype);

int			nm(char *ptr);

int			ar_handle(void *ptr);
int			handle_32(void *ptr);
int			handle_64(void *ptr);
int			fat_handle(void *ptr);

char		get_symbol(u_int8_t symbol, long long *isect, uint8_t n);

void		print_output_64(struct symtab_command *sym, char *ptr, long long sect_n);

int			*sort_nlist(struct symtab_command *sym, char *ptr);

uint64_t	byte_swap(uint64_t k, size_t size);

t_file		*g_file();

#endif
