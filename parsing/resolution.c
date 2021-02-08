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

void	ft_exit(char *error_message)
{
	printf("%s", error_message);
	exit(1);
}

void	check_resolution()
{
	if (g_resolution.hsize <= 0 || g_resolution.vsize <= 0)
	{
		ft_exit("ERROR IN RESOLUTION\nresolution must be strictly positive");
	}
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

//set the resolution to screen size if greater
void	screen_resolution();

void	get_resolution(char **line)
{
	static int reso = 0;

	count_params(line, 3);
	if (reso == 0)
		reso = 1;
	else
		ft_exit("resolutio ERROR\none resolution is allowed");
	line++;
	if (*line != NULL)
	{
		if (!is_number(*line))
			ft_exit("RESOLUTION ERROR\nonly numbers are allowed");
		g_resolution.hsize = ft_atoi(*line);
	}
	line++;
	if (*line != NULL)
	{		
		if (!is_number(*line))
			ft_exit("RESOLUTION ERROR\nonly numbers are allowed");
		g_resolution.vsize = ft_atoi(*line);
	}
	return (check_resolution());
}