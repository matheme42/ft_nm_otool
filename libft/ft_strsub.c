/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 13:32:36 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 17:16:41 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *dest;

	if (!s)
		return (NULL);
	dest = ft_strnew(len);
	if (dest == NULL)
		return (dest);
	dest = ft_strncpy(dest, &s[start], len);
	return (dest);
}
