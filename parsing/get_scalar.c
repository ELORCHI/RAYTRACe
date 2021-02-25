/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scalar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:15:09 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/06 18:15:11 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_scalar_v(char *line, float *scalar)
{
	int i;

	i = 0;
	if (count_comas(line) == -1)
		return (-1);
	i = is_float(line);
	if (i == -1)
	{
		return (-1);
	}
	*scalar = atof(line);
	return (i);
}

int	check_neg(char *line, int i, int *negative)
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

int	hel(char *line, int *i, int *point)
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

int	is_scalar(char *line)
{
	int i;
	int point;
	int digit;
	int negative;

	digit = 0;
	i = 0;
	point = 0;
	negative = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 1 || line[i] == '.' || line[i] == '-')
		{
			if (hel(line, &i, &digit) == -1)
				return (-1);
			else if (check_neg(line, i, &negative) == -1)
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

int get_scalar(char *line, float *scalar)
{
	int i;

	i = is_scalar(line);
	if (i == -1)
		printf("ERROR\n invalide scalar");
	else
		*scalar = ft_atof(line);
	return (i);
}