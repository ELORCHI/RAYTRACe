#ifndef SQUARE_H
#define SQUARE_H

#include "rt.h"
#include "ray.h"
#include "plan.h"

typedef struct 	s_square
{
	t_vector 			center;
	t_vector 			normal;
	t_vector 			color;
	float				side;
	struct s_square 	*next;
} 				t_square;

t_intersection	ray_sqaures_intersection(t_square *square, t_ray ray);
#endif
