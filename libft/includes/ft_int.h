/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlegendr <rlegendr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:18:39 by mjalenqu          #+#    #+#             */
/*   Updated: 2020/12/04 10:00:27 by rlegendr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_INT_H
# define FT_INT_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_str.h"
# include "ft_unix.h"
# include "ft_mem.h"
# include "ft_int.h"
# include "ft_printf.h"
# include "ft_printf_err.h"

int			ft_atoi(const char *str);
int			ft_int_len_base(int n, int base);
int			ft_isdigit(int n);
int			ft_isxdigit(int n);
void		ft_putnbr(int n);
void		ft_putnbr_base(int n, int base);
void		*ft_voidrev(void *s);
void		ft_voidswap(void *s, void *d);
char		*ft_itoa_base_uns(unsigned long long nb, int base);
size_t		check_num_length(long long nb);
uint8_t		swap_uint8t(uint8_t nb);
uint16_t	swap_uint16t(uint16_t nb);
uint32_t	swap_uint32t(uint32_t nb);
uint64_t	swap_uint64t(uint64_t nb);
uint64_t	swap_byte(uint64_t k, size_t size);

#endif
