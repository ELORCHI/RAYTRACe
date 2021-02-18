/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:01:48 by eel-orch          #+#    #+#             */
/*   Updated: 2019/11/05 01:36:37 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	retur(unsigned long j, int sin, int nb_char)
{
	if (nb_char > 8)
	{
		if (sin == -1)
			return (-21474836);
		return (21474836);
	}
	return (j * sin);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sin;
	unsigned long	j;

	i = 0;
	j = 0;
	sin = 1;
	while ((str[i] != '\0' && (str[i] >= 9 && str[i] <= 13)) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sin = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10 + (str[i] - '0');
		i++;
		if (i >= 8)
			return (retur(j, sin, i));
	}
	return (retur(j, sin, i));
}
