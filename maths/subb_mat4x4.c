/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subb_mat4x4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:30:17 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:30:28 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

float			element_4x4(t_mat4x4 *mat, int colomn, int row, int skip)
{
	float		element;
	static int	i = 0;
	t_vector	*vec;

	element = 0.1123;
	vec = ((t_vector *)mat + colomn);
	if (i != 0)
		row += i;
	if (row == skip)
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
	else if (row == 3)
		element = vec->w;
	if (row == 3)
		i = 0;
	return (element);
}

void			plus_plus(int *i, int *help)
{
	(*i)++;
	(*help)++;
}

t_mat3x3		sub_mat4x4(t_mat4x4 *mat4, int colomn, int row)
{
	int			i;
	int			help;
	int			j;
	t_mat3x3	sub;
	t_vec3		vec;

	i = 0;
	help = 0;
	while (i <= 3)
	{
		j = -1;
		if (i == colomn && i < 3)
			i++;
		vec.x = element_4x4(mat4, i, ++j, row);
		vec.y = element_4x4(mat4, i, ++j, row);
		vec.z = element_4x4(mat4, i, ++j, row);
		if (help == 0)
			sub.c1 = vec;
		else if (help == 1)
			sub.c2 = vec;
		else if (help == 2)
			sub.c3 = vec;
		plus_plus(&i, &help);
	}
	return (sub);
}
