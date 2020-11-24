/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:54:55 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 17:00:38 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	int		split(char b, char c)
{
	if (b == c)
		return (1);
	return (0);
}

static	char	**fill_tab(char const *s, char c, char **tab)
{
	int i;
	int size;
	int x;

	x = 0;
	i = 0;
	size = 0;
	while (split(s[i], c) && s[i])
		i++;
	while (s[i])
	{
		while (!split(s[i], c) && s[i])
		{
			tab[x][size] = s[i];
			size++;
			i++;
		}
		while (split(s[i], c) && s[i])
			i++;
		tab[x][size] = '\0';
		x++;
		size = 0;
	}
	tab[x] = NULL;
	return (tab);
}

static	char	**nb_word(char const *s, char c)
{
	char	**tab;
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (split(s[i], c) && s[i])
		i++;
	while (s[i])
	{
		while (!split(s[i], c) && s[i])
			i++;
		word++;
		while (split(s[i], c) && s[i])
			i++;
	}
	if (!(tab = (char**)malloc(sizeof(char*) * (word + 1))))
		return (NULL);
	return (tab);
}

static	char	**word_tab(char const *s, char c, char **tab)
{
	int i;
	int size;
	int x;

	x = 0;
	i = 0;
	size = 0;
	while (split(s[i], c) && s[i])
		i++;
	while (s[i])
	{
		while (!split(s[i], c) && s[i])
		{
			size++;
			i++;
		}
		while (split(s[i], c) && s[i])
			i++;
		if (!(tab[x] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		x++;
		size = 0;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char **tab;

	if (!s)
		return (NULL);
	tab = nb_word(s, c);
	if (tab == NULL)
		return (NULL);
	tab = word_tab(s, c, tab);
	if (tab == NULL)
		return (NULL);
	tab = fill_tab(s, c, tab);
	return (tab);
}
