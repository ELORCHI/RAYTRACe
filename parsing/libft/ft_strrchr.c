/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 20:00:48 by eel-orch          #+#    #+#             */
/*   Updated: 2019/11/10 01:25:22 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int index;

	index = 0;
	while (string[index])
		index++;
	while (index)
	{
		if (string[index] == (char)c)
			return ((char *)(string + index));
		index--;
	}
	if (string[index] == (char)c)
		return ((char *)(string + index));
	return (NULL);
}
