#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

float		dot_product(t_vector vec1, t_vector vec2)
{
	float scalar;

	scalar = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
	return (scalar);
}

t_vector	cross_product(t_vector vec1, t_vector vec2)
{
	t_vector result;

	result.x = vec1.y * vec2.z - vec2.y * vec1.z;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;
	result.w = 0;
	return (result);
}

t_vector	*vector_init(t_vector *vec)
{
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
	vec->w = 0;
	return (vec);
}

t_vector	point_vector(t_vector from, t_vector to)
{
	t_vector vec;
	vec.x = to.x - from.x;
	vec.y = to.y - from.y;
	vec.z = to.z - from.z;
	vec.w = 0;
	return (vec);
}


t_vector	multp_vectors(t_vector vec, float scalar)
{
	vec.x = vec.x * scalar;
	vec.y = vec.y * scalar;
	vec.z = vec.z * scalar;
	vec.w = 0;
	return (vec);
}
