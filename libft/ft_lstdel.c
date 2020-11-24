/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 18:48:04 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 18:58:10 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*maillon;
	t_list	*temp;

	maillon = *alst;
	while (maillon)
	{
		temp = maillon;
		ft_lstdelone(&maillon, del);
		maillon = temp->next;
	}
	*alst = maillon;
}
