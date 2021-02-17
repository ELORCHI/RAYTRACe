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

int count_comas(char *line)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
		{
			nb++;
			if (i == 0)
				return (ft_exit("ERROR\ninvalide vector"));// not allowed first
			else if (ft_isdigit(line[i - 1]) == 0)// must have a digit befor it
				return (ft_exit("ERROR\ninvalide vector"));
			if (line[i + 1] != '\0' && ft_isdigit(line[i + 1]) == 0)//also after and should not be at the end
				return (ft_exit("ERROR\ninvalide vector"));
			if (nb > 2)
				return (ft_exit("ERROR\ninvalide vector"));// should not be more than 2
		}
		i++;
	}
	return (0);
}
t_vector get_vector(char *line)
{
	int 		index;
	int			tmp;
	t_vector	vec;
	
	if (count_comas(line) == -1)
	{
		g_nb_error = -1;
	}
	index = 0;
	tmp = index;
	index += get_scalar(line + index, &(vec.x));
	if (index == tmp)
		g_nb_error = -1;
	tmp = index;
	index += get_scalar(line + index + 1, &(vec.y));
	if (index == tmp)
		g_nb_error = -1;
	tmp = index;
	index += get_scalar(line + index + 2, &(vec.z));
	if (index == tmp)
		g_nb_error = -1;
	else
		g_nb_error = 0;
	if (g_nb_error == -1)
		printf("ERROR\ninvalide vector\n");
	vec.w = 0;
	return (vec);
}
