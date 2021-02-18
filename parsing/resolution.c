/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:11:07 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/01 12:11:13 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_resolution(char **line)
{
	static int reso = 0;

	if (count_params(line, 3) == false)
		return (-1);
	if (reso == 0)
		reso = 1;
	else
		return (ft_exit("ERROR\none resolution is allowed"));
	line++;
	if (*line != NULL)
	{
		if (!is_number(*line))
			return (ft_exit("ERROR\nonly numbers are allowed"));
		g_resolution.hsize = ft_atoi(*line);
	}
	line++;
	if (*line != NULL)
	{		
		if (!is_number(*line))
			return	(ft_exit("ERROR\nonly numbers are allowed"));
		g_resolution.vsize = ft_atoi(*line);
	}
	g_is_resolution = 1;
	return (check_resolution());
}

void	screen_resolution(void)
{
	if (g_resolution.hsize > 2560)
		g_resolution.hsize = 2560;
	if (g_resolution.vsize > 1440)
		g_resolution.vsize = 1400;
}

int	check_resolution(void)
{
	if (g_resolution.hsize <= 0 || g_resolution.vsize <= 0)
	{
		return (ft_exit("ERROR\nresolution must be strictly positive"));
	}
	screen_resolution();
	return (0);
}

bool	is_number(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] >= 48 && line[i] <= 57) || line[i] == '-')
			i++;
		else
			return (false);
	}
	return (true);
}