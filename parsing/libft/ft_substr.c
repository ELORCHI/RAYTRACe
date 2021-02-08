/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 03:17:07 by eel-orch          #+#    #+#             */
/*   Updated: 2019/11/04 04:35:40 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	index;
	int		i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
	{
		if (!(ptr = malloc(1 * sizeof(char))))
			return (0);
		ptr[0] = '\0';
		return (ptr);
	}
	i = 0;
	index = start;
	if ((ptr = (char*)malloc((len + 1) * sizeof(char))))
	{
		while (i < (int)(len) && s[index] != '\0')
			ptr[i++] = s[index++];
		ptr[i] = '\0';
		return (ptr);
	}
	return (0);
}
