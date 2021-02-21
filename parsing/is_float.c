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

int	ft_exit(char *error_message)
{
	printf("%s", error_message);
	return (-1);
}

int	check_negative(char *line, int i, int *negative)
{
	if (line[i] == '-')
	{
		if (line[i + 1] == '\0')
			return (-1);
		(*negative)++;
	}
	if (*negative > 1)
		return (-1);
	return (0);
}

int	helper(char *line, int *i, int *point)
{
	if (line[*i] == '.')
	{
		*point += 1;
		if (line[*i + 1] != '\0')
		{
			if (ft_isdigit(line[*i + 1]) == 1)
				return (0);
			else
				return (-1);
		}
		else
			return (-1);
	}
	return (0);
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
	while (line[i] != '\0' && line[i] != ',')
	{
		if (ft_isdigit(line[i]) == 1 || line[i] == '.' || line[i] == '-')
		{
			if (helper(line, &i, &digit) == -1)
				return (-1);
			else if (check_negative(line, i, &negative) == -1)
				return (-1);
			digit += (ft_isdigit(line[i++]) == 1) ? 1 : 0;
		}
		else
			return (-1);
	}
	if ((point > 1) || (digit == 0))
		return (-1);
	return (i);
}
