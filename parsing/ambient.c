/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:09:40 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/01 12:10:48 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_ambient(char **line)
{
	static int amb = 0;

	if (count_params(line, 3) == false)
		return (-1);
	if (amb == 1)
	{
		printf("ERROR\nambient: only on ambient is allowed");
		return (-1);
	}
	if (amb == 0)
		amb = 1;
	g_is_amb = 1;
	if (line[1] == NULL || line[2] == NULL)
		return (ft_exit("ERROR\n in ambient: few arguments"));
	if (get_scalar(line[1], &(g_embient.ratio)) == -1)
		return (-1);
	if (g_embient.ratio < 0 || g_embient.ratio > 1)
	{
		printf("ERROR\nambient: ratio must be positive less or equal to 1\n");
		return (-1);
	}
	if (get_color(line[2], &(g_embient.color)) == false)
		return (-1);
	return (0);
}
