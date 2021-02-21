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

int	get_scalar(char *line, float *scalar)
{
	int i;

	i = 0;
	if (count_comas(line) == -1)
		return (-1);
	i = is_float(line);
	if (i == -1)
	{
		printf("ERROR\ninvalide scalar\n");
		return (-1);
	}
	*scalar = atof(line);
	return (i);
}
