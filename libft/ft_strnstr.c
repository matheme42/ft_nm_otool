/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 19:49:07 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 15:51:00 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 1;
	if (find[0] == '\0')
		return ((char*)s);
	while (s[i] && i < len)
	{
		if (s[i] == find[0])
		{
			while (s[i + j] == find[j] && find[j] && s[i + j] && i + j < len)
				j++;
			if (find[j] == '\0')
				return (&((char*)s)[i]);
			j = 1;
		}
		i++;
	}
	return (NULL);
}
