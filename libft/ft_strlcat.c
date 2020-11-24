/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 15:13:16 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 18:39:59 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[j] && j < n)
		j++;
	while (s2[k])
		k++;
	k = k + j;
	if (j != n)
	{
		while (s2[i] && j < n - 1)
			s1[j++] = s2[i++];
		s1[j] = '\0';
	}
	return (k);
}
