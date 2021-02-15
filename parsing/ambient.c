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

void	get_ambient(char **line)
{
	static int amb = 0;

	count_params(line, 3);
	if (amb == 1)
	{
		printf("ERROR\n in ambient: only on ambient is allowed");
		exit(0);
	}
	if (amb == 0)
		amb = 1;
	if (line[1] == NULL || line[2] == NULL)
		printf("ERROR\n in ambient: few arguments");
	get_scalar(line[1], &(g_embient.ratio));
	get_color(line[2], &(g_embient.color));
}
