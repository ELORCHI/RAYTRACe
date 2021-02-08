/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:26:04 by eel-orch          #+#    #+#             */
/*   Updated: 2019/11/05 02:15:10 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	srch(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == c)
			return (1);
	}
	return (0);
}

static int	lasts(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == c)
			return (1);
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		str;
	int		end;
	char	*ptr;

	if (s1 == 0)
		return (0);
	index = ft_strlen(s1);
	str = 0;
	end = 0;
	while (s1[str] != '\0' && srch((char *)set, s1[str]))
		str++;
	while (index > 0 && lasts((char *)set, s1[--index]))
		end++;
	if (str + end > (int)ft_strlen(s1))
		end = 0;
	index = 0;
	if ((ptr = (char *)malloc(ft_strlen(s1) + 1 - str - end)))
	{
		while (str < (int)ft_strlen(s1) - end)
			ptr[index++] = s1[str++];
		ptr[index] = '\0';
		return (ptr);
	}
	return (0);
}
