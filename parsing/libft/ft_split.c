/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 04:57:51 by eel-orch          #+#    #+#             */
/*   Updated: 2019/11/04 18:22:40 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *s, char c)
{
	int index;
	int	count;

	if (s == NULL)
		return (0);
	index = -1;
	count = 0;
	if (s[0] != c && s[0])
		count++;
	while (++index < (int)ft_strlen(s))
	{
		if (s[index] == c && s[index + 1] != c && s[index + 1])
			count++;
	}
	return (count);
}

static void	ft_free(char **p, int j)
{
	while (j--)
		free(p[j]);
	free(p);
}

static char	**allo(char **tab, char const *s, int nbwords, char c)
{
	int nballoc;
	int j;
	int index;

	j = -1;
	while (++j < nbwords && *s)
	{
		nballoc = 0;
		while (*s == c)
			s++;
		while (s[nballoc] != c && s[nballoc])
			nballoc++;
		tab[j] = (char *)malloc((nballoc + 1) * sizeof(char));
		if (!tab[j])
		{
			ft_free(tab, j);
			return (0);
		}
		index = -1;
		while (++index < nballoc)
			tab[j][index] = *(s++);
		tab[j][index] = '\0';
	}
	tab[j] = NULL;
	return (tab);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	int		nbwords;

	nbwords = countwords(s, c);
	ptr = (char **)malloc((nbwords + 1) * sizeof(char*));
	if (ptr == NULL)
		return (0);
	return (allo(ptr, s, nbwords, c));
}

char		*skip_tabs(char **line)
{
	char	*new;
	char	*tmp;
	int		index;
	int		len;

	tmp = *line;
	len = ft_strlen(*line);
	new = (char *)malloc(sizeof(char) * (len + 1));
	index = 0;
	while (tmp[index] != '\0')
	{
		if (tmp[index] == 9)
			new[index] = 32;
		else
			new[index] = tmp[index];
		index++;
	}
	new[index] = '\0';
	free(*line);
	return (new);
}
