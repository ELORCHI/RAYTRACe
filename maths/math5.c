#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

t_vector vec4_creat(float a, float b, float c, float d)
{
	t_vector vec;

	vec.x = a;
	vec.y = b;
	vec.z = c;
	vec.w = d;
	return (vec);
}

t_vec2		vec2_creat(float a, float b)
{
	t_vec2 vec;

	vec.x = a;
	vec.y = b;
	return (vec);
}

t_vector	color_multp(t_vector color1, t_vector color2)
{
	t_vector result;

	result.x = color1.x * color2.x;
	result.y = color1.y * color2.y;
	result.z = color1.z * color2.z;
	result.w = 0;
	return (result);
}

bool		vect_cmp(t_vector v1, t_vector v2)
{
	if ((v1.x == v1.y) && (v1.y == v2.y) && (v1.z == v2.z))
		return (true);
	return (false);
}

t_vec3		vec3_creat(float a, float b, float c)
{
	t_vec3 vec3;

	vec3.x = a;
	vec3.y = b;
	vec3.z = c;
	return (vec3);
}