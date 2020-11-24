/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:14:11 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 15:18:54 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	if (len == 0)
		return (NULL);
	while (i < len && ((unsigned char*)b)[i] != (unsigned char)c)
		i++;
	if (i == len)
		return (NULL);
	return (&((void*)b)[i]);
}
