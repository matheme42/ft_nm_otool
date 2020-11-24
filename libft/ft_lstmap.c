/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 13:37:37 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 09:41:34 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *dest;
	t_list *begin;
	t_list *temp;

	if (!lst || !f)
		return (NULL);
	begin = ft_lstnew(lst->content, lst->content_size);
	if (begin == NULL)
		return (NULL);
	begin = f(begin);
	temp = begin;
	lst = lst->next;
	while (lst)
	{
		dest = ft_lstnew(lst->content, lst->content_size);
		if (dest == NULL)
			return (NULL);
		dest = f(dest);
		ft_lstaddback(&temp, dest);
		lst = lst->next;
	}
	return (begin);
}
