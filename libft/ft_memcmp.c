/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:14:06 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 12:01:30 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	size_t i;

	i = 0;
	if (len == 0)
		return (0);
	while (i < len && ((unsigned char*)s1)[i] == ((unsigned char*)s2)[i])
		i++;
	if (i == len)
		i--;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
