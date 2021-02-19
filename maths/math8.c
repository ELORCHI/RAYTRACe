/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:09:45 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/19 19:11:02 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

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

t_mat4x4	identity_mat(void)
{
	t_mat4x4 mat;

	mat.c1 = vec4_creat(1, 0, 0, 0);
	mat.c2 = vec4_creat(0, 1, 0, 0);
	mat.c3 = vec4_creat(0, 0, 1, 0);
	mat.c4 = vec4_creat(0, 0, 0, 1);
	return (mat);
}

t_mat4x4	translation(float x, float y, float z)
{
	t_mat4x4 mat;

	mat = identity_mat();
	mat.c4 = vec4_creat(x, y, z, 1);
	return (mat);
}

t_mat4x4	scaling(float x, float y, float z)
{
	t_mat4x4 mat;

	mat = identity_mat();
	mat.c1.x = x;
	mat.c2.y = y;
	mat.c3.z = z;
	return (mat);
}

t_mat4x4	rotation_x(float teta)
{
	t_mat4x4 mat;

	mat = identity_mat();
	mat.c2.y = cos(teta);
	mat.c2.z = sin(teta);
	mat.c3.y = -1 * mat.c2.z;
	mat.c3.z = mat.c2.y;
	return (mat);
}
