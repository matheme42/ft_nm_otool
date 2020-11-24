/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pointhexa.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 09:51:40 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:17:23 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putadresse2(unsigned long long adr)
{
	char *base;

	base = malloc(sizeof(char) * 17);
	base = "0123456789abcdef\0";
	if (adr / 16 > 0)
		ft_putadresse2(adr / 16);
	ft_putchar(base[adr % 16]);
	free(base);
}

void			ft_putadresse(const void *adresse)
{
	unsigned long long adr;

	ft_putstr("0x");
	adr = (unsigned long long)adresse;
	ft_putadresse2(adr);
}
