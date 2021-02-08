/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 01:00:34 by eel-orch          #+#    #+#             */
/*   Updated: 2019/11/10 01:32:30 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lensrc;
	size_t	lendest;
	size_t	i;
	size_t	lenn;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	lensrc = ft_strlen(src);
	lendest = ft_strlen(dest);
	lenn = lensrc + lendest;
	if (size < lendest)
		lenn = lensrc + size;
	if (size > lendest)
	{
		while (src[i] && (lendest + i) < (size) - 1)
		{
			dest[i + lendest] = src[i];
			i++;
		}
		dest[i + lendest] = '\0';
		lenn = lensrc + lendest;
	}
	return (lenn);
}
