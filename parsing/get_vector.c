/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:14:03 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/06 18:14:06 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int			count_comas(char *line)
{
	int i;
	int nb_comas;
	int test;

	nb_comas = 0;
	i = -1;
	test = 0;
	while (line[++i] != '\0')
	{
		if (line[i] == ',')
		{
			nb_comas++;
			if (nb_comas > 2)
				return (-1);
			if (i == 0)
				return (-1);
			else if (ft_isdigit(line[i - 1]) == 0)
				return (-1);
			if (line[i + 1] == '-')
				test++;
			else if (line[i + 1] == '\0' || ft_isdigit(line[i + 1]) == 0)
				return (-1);
		}
	}
	return (0);
}

t_vector	get_vector(char *line)
{
	int			index;
	int			tmp;
	t_vector	vec;

	if (count_comas(line) == -1)
		g_nb_error = -1;
	index = 0;
	tmp = index;
	index += get_scalar_v(line + index, &(vec.x));
	if (index <= tmp)
		g_nb_error = -1;
	tmp = index;
	index += get_scalar_v(line + index + 1, &(vec.y));
	if (index <= tmp)
		g_nb_error = -1;
	tmp = index;
	index += get_scalar_v(line + index + 2, &(vec.z));
	if (index <= tmp)
		g_nb_error = -1;
	if (g_nb_error == -1)
		printf("ERROR\ninvalide vector\n");
	vec.w = 0;
	return (vec);
}
