/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:38:18 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:38:26 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

void		scale_mat4(t_mat4x4 *mat, float scalar)
{
	t_mat4x4 scaling;

	scaling = identity_mat();
	scaling.c1.x = scalar;
	scaling.c2.y = scalar;
	scaling.c3.z = scalar;
	*mat = mat_multp(*mat, scaling);
}

float		minor_3x3(t_mat3x3 *mat3, int colomn, int row)
{
	float		minor;
	t_mat2x2	mat2;

	minor = element_3x3(mat3, colomn, row, 110);
	mat2 = sub_mat3x3(mat3, colomn, row);
	minor = minor * determinant_2x2(&mat2);
	return (minor);
}

float		cofactor_3x3(t_mat3x3 *mat3, int colomn, int row)
{
	float	minore;
	float	cofactor;
	int		modulo;

	modulo = (colomn + row) % 2;
	cofactor = 1;
	minore = minor_3x3(mat3, colomn, row);
	if (modulo == 0)
		cofactor = -1;
	return (minore * cofactor);
}

float		minor_4x4(t_mat4x4 *mat4, int colomn, int row, int skip)
{
	float		minor;
	t_mat3x3	mat3;

	minor = 1;
	if (skip == 1)
		minor = element_4x4(mat4, colomn, row, -7);
	mat3 = sub_mat4x4(mat4, colomn, row);
	minor = minor * determinant_3x3(&mat3, colomn);
	return (minor);
}

float		cofactor_4x4(t_mat4x4 *mat4, int colomn, int row, int skip)
{
	float	minor;
	float	cofactor;
	int		modulo;

	modulo = (row + colomn) % 2;
	cofactor = 1;
	minor = minor_4x4(mat4, colomn, row, skip);
	if (modulo == 0)
		cofactor = -1;
	return (minor * cofactor);
}
