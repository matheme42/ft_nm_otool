/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_recursive_power.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/06 11:01:41 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 11:50:32 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	return (ft_power(nb, power - 1) * nb);
}
