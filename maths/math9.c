#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

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

t_mat4x4	shearing(t_shearing shear)
{
	t_mat4x4 mat;

	mat = identity_mat();
	mat.c1.y = shear.y_to_x;
	mat.c1.z = shear.z_to_x;
	mat.c2.x = shear.x_to_y;
	mat.c2.z = shear.z_to_y;
	mat.c3.x = shear.x_to_z;
	mat.c3.y = shear.y_to_z;
	return (mat);
}

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
	float 		minor;
	t_mat2x2	mat2;

	minor = element_3x3(mat3, colomn, row, 110);
	mat2 = sub_mat3x3(mat3, colomn, row);
	minor = minor * determinant_2x2(&mat2);
	return (minor);
}