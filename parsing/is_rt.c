/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:01:20 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/11 16:01:21 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_strcmp(const char *first, const char *second)
{
	int i;

	i = 0;
	while ((first[i] != '\0' || second[i] != '\0'))
	{
		if (first[i] != second[i])
			return ((unsigned char)first[i] - (unsigned char)second[i]);
		i++;
	}
	return (0);
}

int is_rt(char *line)
{
	int len;

	len = ft_strlen(line);
	if (len < 3)
	{
		ft_exit("ERROR\ninvalide scene argument");
		exit(0);
		return (-1);
	}
	if (ft_strncmp(line + len - 3, ".rt", 3) != 0)
	{
		printf("ERROR\nInvalide scene argument");
		exit(0);
		return(-1);
	}
	return (1);
}

int	is_save(char *line)
{
	if (ft_strcmp(line, "--save") != 0)
	{
		printf("ERROR\nInvalide saving argument");
		exit(0);
		return (-1);
	}
	return (0);
}