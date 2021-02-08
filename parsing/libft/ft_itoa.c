/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:39:40 by eel-orch          #+#    #+#             */
/*   Updated: 2019/11/04 19:24:13 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fcount(long d)
{
	int count;

	count = 1;
	while (d / 10 != 0)
	{
		d = d / 10;
		count++;
	}
	return (count);
}

static char	*remp(char *tab, long integer, int sign, int len)
{
	int loop;
	int i;

	loop = len;
	i = len;
	if (sign < 0)
	{
		tab[0] = '-';
		i--;
	}
	while (i--)
	{
		tab[--len] = integer % 10 + '0';
		integer = integer / 10;
	}
	tab[loop] = '\0';
	return (tab);
}

char		*ft_itoa(int n)
{
	int		count;
	int		index;
	long	longn;
	char	*ptr;

	count = 1;
	index = 1;
	ptr = NULL;
	longn = (long)n;
	if (n >= 0)
		count = fcount(longn);
	else
	{
		count = fcount(-1 * longn) + 1;
		longn = -1 * longn;
		index = -1;
	}
	ptr = (char *)malloc(++count * sizeof(char));
	if (ptr == 0)
		return (0);
	return (remp(ptr, longn, index, count - 1));
}
