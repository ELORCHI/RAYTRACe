/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:02:09 by eel-orch          #+#    #+#             */
/*   Updated: 2019/11/10 01:26:51 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					index;
	const unsigned char	*src;

	index = 0;
	src = (const unsigned char *)s;
	while (n--)
	{
		if (src[index] == (unsigned char)c)
			return ((unsigned char *)(s + index));
		index++;
	}
	return (NULL);
}
