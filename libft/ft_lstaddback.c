/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstaddback.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 17:45:24 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/13 14:46:54 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **begin_list, t_list *list)
{
	while ((*begin_list)->next != NULL)
		*begin_list = (*begin_list)->next;
	(*begin_list)->next = list;
}
