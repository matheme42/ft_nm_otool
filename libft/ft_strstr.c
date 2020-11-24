/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 19:36:20 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 17:16:35 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (find[0] == '\0')
		return ((char*)str);
	while (str[i])
	{
		if (str[i] == find[0])
		{
			while (str[i + j] == find[j] && find[j] && str[i + j])
				j++;
			if (find[j] == '\0')
				return (&((char*)str)[i]);
			j = 1;
		}
		i++;
	}
	return (NULL);
}
