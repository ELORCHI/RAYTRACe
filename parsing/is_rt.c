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

int is_rt(char *line)
{
	int len;

	len = ft_strlen(line);
	if (len < 3)
	{
		ft_exit("ERROR\ninvalide scene argument");
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

void	is_save(char *line)
{
	if (ft_strncmp(line, "save", 4) != 0)
	{
		printf("ERROR\nInvalide saving argument");
			exit(0);
	}
}