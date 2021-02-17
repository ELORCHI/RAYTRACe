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
		printf("ERROR\n in ambient: few arguments");
	if (get_scalar(line[1], &(g_embient.ratio)) == -1)
		return (-1);
	if (g_embient.ratio < 0)
	{
		printf("ERROR\nambient: ambient ratio must be positive\n");
		return (-1);
	}
	get_color(line[2], &(g_embient.color));
	return (0);
}

int main ()
{
	char *line1 = ft_strdup("A 2.22, 255,255,255,");
	char *line2 = ft_strdup("A 2.2 255,255,255");

	line1 = skip_tabs(&line1);
	line2 = skip_tabs(&line2);

	char **params1 = ft_split(line1, 32);
	char **params2 = ft_split(line2, 32);
	get_ambient(params1);
	print_vector(g_embient.color);
	printf("%f\n", g_embient.ratio);
	// get_ambient(params2);
}