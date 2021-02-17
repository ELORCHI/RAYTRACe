#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

void 	print_mat4(t_mat4x4 mat)
{
	printf("=============================\n");
	printf("===========MAT4X4============\n");
	printf("%f %f %f %f\n", mat.c1.x ,mat.c2.x, mat.c3.x, mat.c4.x);
	printf("%f %f %f %f\n", mat.c1.y, mat.c2.y, mat.c3.y, mat.c4.y);
	printf("%f %f %f %f\n", mat.c1.z, mat.c2.z, mat.c3.z, mat.c4.z);
	printf("%f %f %f %f\n", mat.c1.w, mat.c2.w, mat.c3.w, mat.c4.w);
	printf("=============================\n");
}

void print_vector(t_vector vec2)
{
	printf("=============================\n");
	printf("==========4DVECTOR===========\n");
	printf("%f\n%f\n%f\n%f\n", vec2.x ,vec2.y, vec2.z, vec2.w);
}

t_vector	point_to_vector(t_vector point)
{
	t_vector vec;

	vec.x = point.x;
	vec.y = point.y;
	vec.z = point.z;
	vec.w = 0;
	return (vec);
}

float		magnitude(t_vector vec)
{
	float magn;

	magn = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (magn);
}

t_vector	normaliz(t_vector vec)
{
	float magn;

	magn = magnitude(vec);
	if (magn > 0)
	{
		magn = 1 / magn;
		vec.x = vec.x * magn;
		vec.y = vec.y * magn;
		vec.z = vec.z * magn;
		vec.w = 0;
	}
	return (vec);
}
