/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subb_mat3x3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:32:55 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:32:57 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

float		element_3x3(t_mat3x3 *mat, int colomn, int row, int row2)
{
	float		element;
	static	int i = 0;
	t_vec3		*vec;

	element = 0.0456;
	if (colomn == 3)
		colomn--;
	vec = ((t_vec3 *)mat + colomn);
	if (i != 0)
		row += i;
	if (row == row2)
	{
		i++;
		row += i;
	}
	if (row == 0)
		element = vec->x;
	else if (row == 1)
		element = vec->y;
	else if (row == 2)
		element = vec->z;
	if (row == 2)
		i = 0;
	return (element);
}

t_mat2x2	sub_mat3x3(t_mat3x3 *mat3, int colomn, int row)
{
	int			i;
	int			j;
	t_mat2x2	sub;
	t_vec2		vec;
	int			help;

	i = 0;
	help = 0;
	while (i <= 2)
	{
		j = -1;
		if (i == colomn && colomn < 2)
			i++;
		vec.x = element_3x3(mat3, i, ++j, row);
		vec.y = element_3x3(mat3, i, ++j, row);
		if (help == 0)
			sub.c1 = vec;
		if (help == 1)
			sub.c2 = vec;
		i++;
		help++;
	}
	return (sub);
}
