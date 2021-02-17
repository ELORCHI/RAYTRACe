/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 03:51:24 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/12 12:40:09 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdio.h>
float	determinant_2x2(t_mat2x2 *mat2)
{
	float deter;

	deter = (mat2->c1).x * (mat2->c2).y - (mat2->c2).x * (mat2->c1).y;
	return (deter);
}

float	determinant_3x3(t_mat3x3 *mat3, int colomn)
{
	int			i;
	float 		deter;
	float 		cofactor;

	deter = 0;
	cofactor = 0;
	i = 0;
	if (colomn == 3)
		colomn--;
	while (i < 3)
	{
		cofactor = cofactor_3x3(mat3, colomn,i);
		deter += cofactor;
		i++;
	}
	return (deter);
}

float	determinant_4x4(t_mat4x4 *mat4, int colomn)
{
	int 		i;
	float		deter;
	float		cofactor;

	deter = 0;
	cofactor = 0;
	i = 0;
	while (i < 4)
	{
		cofactor = cofactor_4x4(mat4, colomn, i, 1);
		deter += cofactor;
		i++;
	}
	return (deter);
}

bool	inverse_4x4(t_mat4x4 *inverse, t_mat4x4 *mat)
{
	float 		deter;
	int			i;
	int			row;
	t_vector 	*vec;

	i = 0;
	row = 0;
	deter = determinant_4x4(mat, 0);
	if (deter == 0)
		return (false);
	deter = 1 / deter;
	while (i < 4)
	{
		row = -1;
		vec = ((t_vector *)inverse + i);
		vec->x = cofactor_4x4(mat, i, ++row, 0) * deter;
		vec->y = cofactor_4x4(mat, i, ++row, 0) * deter;
		vec->z = cofactor_4x4(mat, i, ++row, 0) * deter;
		vec->w = cofactor_4x4(mat, i, ++row, 0) * deter;
		i++;
	}
	*inverse = transpose(*inverse); 
	return (true);
}
