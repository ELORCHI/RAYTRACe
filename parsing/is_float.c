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
			point += (line[i] == '.') ? 1 : 0;
			digit += (ft_isdigit(line[i]) == 1) ? 1 : 0;
			negative += (line[i] == '-') ? 1 : 0;
			i++;
		}
		else
			return (0);	
	}
	if (point > 1 || digit == 0)
		return (0);
	return (i);
}	