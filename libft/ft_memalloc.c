/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 10:51:01 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 17:11:10 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *p;

	if (!(p = (void*)malloc(sizeof(char) * (size))))
		return (NULL);
	while (size > 0)
	{
		p[size] = 0;
		size--;
	}
	p[size] = 0;
	return ((void*)p);
}
