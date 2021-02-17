/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:10:36 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/06 18:10:41 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// needs change
// no negative sign after point
//vergule must be  max to
// only numbers are allowed after .


int	helper(char *line, int *i, int *digit, int *negative, int *point)
{
	if (ft_isdigit(line[*i]) == 1 || line[*i] == '.' || line[*i] == '-')
	{
		if (line[*i] == '.')
		{
			*point += 1;
			if (line[*i + 1] == '\0')
			{
				if (ft_isdigit(line[*i + 1]) == 0)
					return (0);
			}
			else
				return (0);
		}
		*digit += (ft_isdigit(line[*i]) == 1) ? 1 : 0;
		if (*negative > 1)
			return (0);
	}
	return (-1);
}

int	is_float(char *line)
{
	int i;
	int point;
	int digit;
	int negative;

	digit = 0;
	i = 0;
	point = 0;
	negative = 0;
	while (line[i] != '\0' && line[i] != ',' && (point == 0 || point == 1))
	{
		if (ft_isdigit(line[i]) == 1 || line[i] == '.' || line[i] == '-')
		{
			helper(line, &i, &digit, &negative, &point);
			i++;
		}
		else
			return (0);	
	}
	if (point > 1 || digit == 0 || negative > 1)
		return (0);
	return (i);
}	