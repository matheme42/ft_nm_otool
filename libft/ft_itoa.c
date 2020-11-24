/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 16:35:21 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 15:35:39 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_malloc_itoa(int n)
{
	char	*str;
	int		t;

	t = 1;
	if (n < 0)
		t++;
	else
		n = -n;
	while (n <= -10)
	{
		n = n / 10;
		t += 1;
	}
	str = (char*)malloc(sizeof(char) * (t + 1));
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		t;
	int		i;

	str = ft_malloc_itoa(n);
	if (str == NULL)
		return (NULL);
	i = 0;
	t = 1;
	if (n < 0)
		str[i++] = '-';
	else
		n = -n;
	while (n / t <= -10)
		t *= 10;
	while (t >= 1)
	{
		str[i++] = (-(n / t - '0'));
		n = n % t;
		t /= 10;
	}
	str[i] = '\0';
	return (str);
}
