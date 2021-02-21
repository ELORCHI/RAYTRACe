/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:00:49 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/19 19:00:50 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

t_mat2x2	mat2_creat(t_vec2 v1, t_vec2 v2)
{
	t_mat2x2 mat;

	mat.c1 = v1;
	mat.c2 = v2;
	return (mat);
}

t_mat3x3	mat3_creat(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	t_mat3x3 mat;

	mat.c1 = v1;
	mat.c2 = v2;
	mat.c3 = v3;
	return (mat);
}

float		element_4x4(t_mat4x4 *mat, int colomn, int row, int skip)
{
	float		element;
	static int	i = 0;
	t_vector	*vec;

	element = 0.1123;
	vec = ((t_vector *)mat + colomn);
	//row += (i != 0) ? i : 0;
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
	//i = (row == 3) ? 0 : i;
	if (row == 3)
		i = 0;
	return (element);
}

t_mat3x3	sub_mat4x4(t_mat4x4 *mat4, int colomn, int row)
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
		//i = (i == colomn && i < 3) ? i++ : i;
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
		i++;
		help++;
	}
	return (sub);
}

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
