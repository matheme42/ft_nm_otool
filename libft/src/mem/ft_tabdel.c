/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tabdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rlegendr <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/20 15:22:31 by rlegendr     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/20 15:27:07 by rlegendr    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_mem.h"

void	ft_tabdel(char **tabl)
{
	int		i;

	i = 0;
	while (tabl[i])
	{
		free(tabl[i]);
		i += 1;
	}
	free(tabl);
}