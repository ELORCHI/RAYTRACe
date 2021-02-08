/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 03:41:53 by eel-orch          #+#    #+#             */
/*   Updated: 2019/10/27 17:07:00 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char c))
{
	char	*ptr;
	int		index;
	int		count;

	if (s == 0)
		return (0);
	index = 0;
	count = (int)ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (count + 1));
	if (ptr)
	{
		while (index < count)
		{
			ptr[index] = f((unsigned int)index, ((char *)s)[index]);
			index++;
		}
		ptr[index] = '\0';
		return (ptr);
	}
	return (0);
}
