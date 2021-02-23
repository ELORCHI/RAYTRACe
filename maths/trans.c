/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:36:44 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:36:50 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

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

t_mat4x4	rotation_z(float teta)
{
	t_mat4x4 mat;

	mat = identity_mat();
	mat.c1.x = cos(teta);
	mat.c1.y = sin(teta);
	mat.c2.x = -1 * mat.c1.y;
	mat.c2.y = mat.c1.x;
	return (mat);
}

t_mat4x4	rotation_y(float teta)
{
	t_mat4x4 mat;

	mat = identity_mat();
	mat.c1.x = cos(teta);
	mat.c1.z = -1 * sin(teta);
	mat.c3.x = -1 * mat.c1.z;
	mat.c3.z = mat.c1.x;
	return (mat);
}
