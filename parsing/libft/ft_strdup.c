/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 00:52:28 by eel-orch          #+#    #+#             */
/*   Updated: 2019/11/10 01:19:37 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		j;
	int		index;
	char	*ptr;

	index = 0;
	j = -1;
	while (s[index])
		index++;
	index++;
	ptr = malloc(index * sizeof(char));
	if (ptr)
	{
		while (s[++j])
			ptr[j] = s[j];
		ptr[j] = '\0';
		return (ptr);
	}
	return (NULL);
}
