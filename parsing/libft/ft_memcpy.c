/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:58:56 by eel-orch          #+#    #+#             */
/*   Updated: 2019/11/09 21:39:37 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *tab;
	unsigned char *ptr;

	tab = (unsigned char *)src;
	ptr = (unsigned char *)dst;
	if (tab == 0 && ptr == 0)
		return (0);
	while (n--)
		*ptr++ = *tab++;
	return (dst);
}
