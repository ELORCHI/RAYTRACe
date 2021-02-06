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

bool	is_float(char *line)
{
	int i;
	int point;
	int digit;

	digit = 0;
	i = 0;
	point = 0;
	while (line[i] != '\0' && (point == 0 || point == 1))
	{
		if (ft_isdigit(line[i]) == 1 || line[i] == '.')
		{
		  point += (line[i] == '.') ? 1 : 0;
		  digit += (ft_isdigit(line[i]) == 1) ? 1 : 0;
			i++;
		}
		else
			return (false);	
	}
	if (point > 1 || digit == 0)
		return (false);
	return (true);
}	