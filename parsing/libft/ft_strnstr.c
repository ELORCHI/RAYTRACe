/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 01:32:48 by eel-orch          #+#    #+#             */
/*   Updated: 2019/11/10 02:01:29 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *fulls, const char *subs, size_t len)
{
	size_t index;
	size_t j;
	size_t t;

	j = 0;
	if (*subs == 0)
		return ((char *)fulls);
	while (j < len && fulls[j])
	{
		t = j;
		index = 0;
		while (fulls[t] == subs[index] && (j + index) < len)
		{
			index++;
			if (subs[index] == '\0')
				return ((char *)(fulls + (t - index + 1)));
			t++;
		}
		j++;
	}
	return (0);
}
