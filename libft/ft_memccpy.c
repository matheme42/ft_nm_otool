/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:14:17 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 16:36:40 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	size_t i;

	i = 0;
	if (len == 0)
		return (NULL);
	while (((unsigned char*)src)[i] != (unsigned char)c && i < len)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	if (i == len)
		return (NULL);
	((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
	return (&dest[i + 1]);
}
